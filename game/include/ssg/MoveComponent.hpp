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

    private:
        Vector2D m_Acceleration;

        float m_Speed;
    };
}
