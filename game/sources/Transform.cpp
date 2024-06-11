#include "ssg/Transform.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"  

namespace ssg
{
    /*static*/ bool Transform::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<Transform>("Transform", sol::constructors<Transform(), Transform(const Vector2D&, const float, const Vector2D&)>(),
                                                        "size", &Transform::m_Size,
                                                        "rotation", &Transform::m_Rotation,
                                                        "position", &Transform::m_Position,
                                                        "origin", &Transform::m_Origin);
                    }
                }
            }
        }
        catch(...)
        {
            return false;
        }

        return true;
    }

    Transform::Transform()
        : m_Size({ 1.0f, 1.0f })
        , m_Position({ 0.0f, 0.0f })
        , m_Rotation(0.0f)
        , m_Origin({ 0.0f, 0.0f })
    {

    }

    Transform::Transform(const Vector2D& InSize, const float InRotation, const Vector2D& InPosition)
        : m_Size(InSize)
        , m_Position(InPosition)
        , m_Rotation(InRotation)
        , m_Origin({ 0.0f, 0.0f })
    {

    }

    Transform::Transform(const Vector2D& InSize, const float InRotation, const Vector2D& InPosition, const Vector2D& InOrigin)
        : m_Size(InSize)
        , m_Position(InPosition)
        , m_Rotation(InRotation)
        , m_Origin(InOrigin)
    {

    }
        
    Transform::~Transform() = default;

    Transform::Transform(const Transform& InObj)
        : m_Size(InObj.m_Size)
        , m_Position(InObj.m_Position)
        , m_Rotation(InObj.m_Rotation)
        , m_Origin(InObj.m_Origin)
    {

    }

    Transform& Transform::operator=(const Transform& InObj)
    {
        if (this != &InObj)
        {
            m_Size = InObj.m_Size;
            m_Position = InObj.m_Position;
            m_Rotation = InObj.m_Rotation;
            m_Origin = InObj.m_Origin;
        }

        return *this;
    }

    void Transform::AddPosition(const Vector2D& InOffset)
    {
        m_Position += InOffset;
    }
}