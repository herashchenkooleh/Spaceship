#pragma once

#include "Vector2D.hpp"
#include "GameObjectComponent.hpp"

namespace SpaceShipGame
{
    class MoveComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<MoveComponent>;

        MoveComponent();
        ~MoveComponent();

        virtual void Update(const float InDeltaTime) override;

        void SetXSpeed(const float InSpeed) { m_Speed.SetX(InSpeed); };
        void SetYSpeed(const float InSpeed) { m_Speed.SetY(InSpeed); };

        const Vector2D& GetSpeed() const { return m_Speed; };

    private:
        Vector2D m_Speed;
    };
}