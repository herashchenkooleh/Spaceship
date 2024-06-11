#pragma once

#include "ssg/Vector2D.hpp"

namespace ssg
{
    class Transform
    {
    public:
        Transform();
        Transform(const Vector2D& InSize, const float InRotation, const Vector2D& InPosition);
        Transform(const Vector2D& InSize, const float InRotation, const Vector2D& InPosition, const Vector2D& InOrigin);
        ~Transform();

        Transform(const Transform& InObj);
        Transform& operator=(const Transform& InObj);

        const Vector2D& GetSize() const { return m_Size; }
        void SetSize(const Vector2D& InSize) { m_Size = InSize; }

        float GetRotation() const { return m_Rotation; }
        void SetRotation(const float InRotation) { m_Rotation = InRotation;}

        const Vector2D& GetPosition() const { return m_Position; }
        void SetPosition(const Vector2D& InPosition) { m_Position = InPosition; }

        void AddPosition(const Vector2D& InOffset);

        static bool RegisterScriptType();

        Vector2D GetOrigin() const { return m_Origin; }
        void SetOrigin(const Vector2D& InOrigin) { m_Origin = InOrigin; }

    private:
        Vector2D m_Size;
        Vector2D m_Position;
        float m_Rotation;
        Vector2D m_Origin;
    };
}