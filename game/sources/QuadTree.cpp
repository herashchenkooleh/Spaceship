#include "ssg/QuadTree.hpp"

namespace ssg
{
    QuadTree::QuadTree()
        : QuadTree(5, 5, 0, {{ 0.0f, 0.0f }, { 800.0f, 600.0f }}, nullptr)
    {

    }

    QuadTree::QuadTree(int InMaxObjects, int InMaxLevels, int InLevel, const FloatRect& InBounds, QuadTree* InParent)
        : m_MaxObjects(InMaxObjects)
        , m_MaxLevels(InMaxLevels)
        , m_Bounds(InBounds)
        , m_Parent(InParent)
    {

    }

    QuadTree::~QuadTree() = default;

    void QuadTree::Insert(CollisionComponent::Ptr InObject)
    {
        if(m_Children[0] != nullptr)
        {
            int indexToPlaceObject = GetChildIndexForObject(InObject->GetCollidable());
            if(indexToPlaceObject != s_ThisTree)
            {
                m_Children[indexToPlaceObject]->Insert(InObject);
                return;
            }
        }
        
        m_Objects.emplace_back(InObject);
        
        if(m_Objects.size() > m_MaxObjects && m_Level < m_MaxLevels && m_Children[0] == nullptr)
        {
            Split();
            
            auto ObjIterator = m_Objects.begin(); // 7
            while (ObjIterator != m_Objects.end())
            {
                auto Obj = *ObjIterator;
                int indexToPlaceObject = 
                    GetChildIndexForObject(Obj->GetCollidable());
                
                if (indexToPlaceObject != s_ThisTree)
                {
                    m_Children[indexToPlaceObject]->Insert(Obj);
                    ObjIterator = m_Objects.erase(ObjIterator);
                
                }
                else
                {
                    ++ObjIterator;
                }
            }
        }
    }

    void QuadTree::Remove(CollisionComponent::Ptr InObject)
    {
        int Index = GetChildIndexForObject(InObject->GetCollidable());
        
        if(Index == s_ThisTree || m_Children[Index] == nullptr)
        {
            for(int i = 0; i < m_Objects.size(); i++)
            {
                if(m_Objects.at(i)->GetID() == InObject->GetID())
                {
                    m_Objects.erase(m_Objects.begin() + i);
                    break;
                }
            }
        }
        else
        {
            return m_Children[Index]->Remove(InObject);
        }
    }

    void QuadTree::Clear()
    {
        m_Objects.clear();
        
        for(int i = 0; i < 4; i++)
        {
            if(m_Children[i] != nullptr)
            {
                m_Children[i]->Clear();
                m_Children[i] = nullptr;
            }
        }
    }

    Vector<CollisionComponent::Ptr> QuadTree::Search(const FloatRect& InArea)
    {
        Vector<CollisionComponent::Ptr> PossibleOverlaps;
        Search(InArea, PossibleOverlaps);
        
        Vector<CollisionComponent::Ptr> ReturnList;
        ReturnList.reserve(PossibleOverlaps.size());
        
        for (auto Collider : PossibleOverlaps)
        {
            if (InArea.findIntersection(Collider->GetCollidable()))
            {
                ReturnList.emplace_back(Collider);
            }
        }

        return ReturnList;
    }

    void QuadTree::Search(const FloatRect& InArea, Vector<CollisionComponent::Ptr>& InOverlappingObjects)
    {
        InOverlappingObjects.insert(InOverlappingObjects.end(), m_Objects.begin(), m_Objects.end());
        
        if(m_Children[0] != nullptr)
        {
            int Index = GetChildIndexForObject(InArea);
            
            if(Index == s_ThisTree)
            {
                for(int i = 0; i < 4; i++)
                {
                    if(m_Children[i]->GetBounds().findIntersection(InArea))
                    {
                        m_Children[i]->Search(InArea, InOverlappingObjects);
                    }
                }
            }
            else
            {
                m_Children[Index]->Search(InArea, InOverlappingObjects);
            }
        }
    }

    int QuadTree::GetChildIndexForObject(const FloatRect& InObjectBounds)
    {
        int Index = -1;

        double VerticalDividingLine = m_Bounds.left + m_Bounds.width * 0.5f;
        double HorizontalDividingLine = m_Bounds.top + m_Bounds.height * 0.5f;
        
        bool North = InObjectBounds.top < HorizontalDividingLine && (InObjectBounds.height + InObjectBounds.top < HorizontalDividingLine);
        bool South = InObjectBounds.top > HorizontalDividingLine;
        bool West = InObjectBounds.left < VerticalDividingLine && (InObjectBounds.left + InObjectBounds.width < VerticalDividingLine);
        bool East = InObjectBounds.left > VerticalDividingLine;
        
        if(East)
        {
            if(North)
            {
                Index = s_ChildNE;
            }
            else if(South)
            {
                Index = s_ChildSE;
            }
        }
        else if(West)
        {
            if(North)
            {
                Index = s_ChildNW;
            }
            else if(South)
            {
                Index = s_ChildSW;
            }
        }
        
        return Index;
    }

    void QuadTree::Split()
    {
        const float ChildWidth = static_cast<float>(m_Bounds.width) / 2.0f;
        const float ChildHeight = static_cast<float>(m_Bounds.height) / 2.0f;
        
        m_Children[s_ChildNE] = MakeShared<QuadTree>(m_MaxObjects, m_MaxLevels, m_Level + 1, FloatRect({ m_Bounds.left + ChildWidth, m_Bounds.top }, { ChildWidth, ChildHeight }), this);
        m_Children[s_ChildNW] = MakeShared<QuadTree>(m_MaxObjects, m_MaxLevels, m_Level + 1, FloatRect({ m_Bounds.left, m_Bounds.top }, { ChildWidth, ChildHeight }), this);
        m_Children[s_ChildSW] = MakeShared<QuadTree>(m_MaxObjects, m_MaxLevels, m_Level + 1, FloatRect({ m_Bounds.left, m_Bounds.top + ChildHeight }, { ChildWidth, ChildHeight }), this);
        m_Children[s_ChildSE] = MakeShared<QuadTree>(m_MaxObjects, m_MaxLevels, m_Level + 1, FloatRect({ m_Bounds.left + ChildWidth, m_Bounds.top + ChildHeight }, { ChildWidth, ChildHeight }), this);
    }
}