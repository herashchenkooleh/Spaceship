#include "ssg/Transform.hpp"

namespace ssg
{
    Transform::Transform()
        : m_Scale({ 1.0f, 1.0f })
        , m_Position({ 0.0f, 0.0f })
        , m_Rotation(0.0f)
    {

    }

    Transform::Transform(const Vector2D& InScale, const float InRotation, const Vector2D& InPosition)
        : m_Scale(InScale)
        , m_Position(InPosition)
        , m_Rotation(InRotation)
    {

    }
        
    Transform::~Transform() = default;

    Transform::Transform(const Transform& InObj)
        : m_Scale(InObj.m_Scale)
        , m_Position(InObj.m_Position)
        , m_Rotation(InObj.m_Rotation)
    {

    }

    Transform& Transform::operator=(const Transform& InObj)
    {
        if (this != &InObj)
        {
            m_Scale = InObj.m_Scale;
            m_Position = InObj.m_Position;
            m_Rotation = InObj.m_Rotation;
        }

        return *this;
    }
}