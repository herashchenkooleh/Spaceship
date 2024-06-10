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

        void SetSpeed(const Vector2D& InSpeed) { m_Speed = InSpeed; }
        const Vector2D& GetSpeed() const { return m_Speed; }

    private:
        Vector2D m_Speed;
    };
}
