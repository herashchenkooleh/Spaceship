#pragma once

#include "ssg/Vector2D.hpp"
#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class MoveComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<MoveComponent>;

        MoveComponent();
        ~MoveComponent();

        virtual void Update(const float InDeltaTime) override;

        void SetAcceleration(const Vector2D& InSpeed) { m_Acceleration = InSpeed; }
        const Vector2D& GetAcceleration() const { return m_Acceleration; }

        void SetSpeed(const float InSpeed) { m_Speed = InSpeed; };
        float GetSpeed() const { return m_Speed; }

        void SetLookAt(const Vector2D& InLookAt) { m_LookAt = InLookAt; }
        const Vector2D& GetLookAt() const { return m_LookAt; } 

    private:
        Vector2D m_Acceleration;
        Vector2D m_LookAt;

        float m_Speed;
    };
}
