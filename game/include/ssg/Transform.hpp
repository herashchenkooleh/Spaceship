#pragma once

#include "ssg/Vector2D.hpp"

namespace ssg
{
    class Transform
    {
    public:
        Transform();
        Transform(const Vector2D& InScale, const float InRotation, const Vector2D& InPosition);
        ~Transform();

        Transform(const Transform& InObj);
        Transform& operator=(const Transform& InObj);

        const Vector2D& GetScale() const { return m_Scale; }
        void SetScale(const Vector2D& InScale) { m_Scale = InScale; }

        float GetRotation() const { return m_Rotation; }
        void SetRotation(const float InRotation) { m_Rotation = InRotation;}

        const Vector2D& GetPosition() const { return m_Position; }
        void SetPosition(const Vector2D& InPosition) { m_Position = InPosition; }

        void AddPosition(const Vector2D& InOffset);

    private:
        Vector2D m_Scale;
        Vector2D m_Position;
        float m_Rotation;
    };
}