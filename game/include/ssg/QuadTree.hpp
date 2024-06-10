#pragma once

#include "ssg/CollisionComponent.hpp"
#include "ssg/Global.hpp"

namespace ssg
{
    class QuadTree
    {
    public:
        using Ptr = SharedPtr<QuadTree>;

        QuadTree();
        QuadTree(int InMaxObjects, int InMaxLevels, int InLevel, const FloatRect& InBounds, QuadTree* InParent);
        ~QuadTree();

        QuadTree(const QuadTree& InObject) = delete;
        QuadTree& operator=(const QuadTree& InObject) = delete;
    
        void Insert(CollisionComponent::Ptr InObject);
        void Remove(CollisionComponent::Ptr InObject);
	
        void Clear();
    
	    Vector<CollisionComponent::Ptr> Search(const FloatRect& InArea);
    
        const FloatRect& GetBounds() const { return m_Bounds; }
    
    private:
	    void Search(const FloatRect& InArea, Vector<CollisionComponent::Ptr>& InOverlappingObjects);

        int GetChildIndexForObject(const sf::FloatRect& objectBounds);
        void Split();
    
        static const int s_ThisTree = -1;
        static const int s_ChildNE = 0;
        static const int s_ChildNW = 1;
        static const int s_ChildSW = 2;
        static const int s_ChildSE = 3;
    
        int m_MaxObjects;
        int m_MaxLevels;
    
        QuadTree* m_Parent;
        QuadTree::Ptr m_Children[4];

        Vector<CollisionComponent::Ptr> m_Objects;
        int m_Level;
    
        FloatRect m_Bounds;
    };
}