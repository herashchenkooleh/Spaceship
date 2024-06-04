#pragma once

#include "GameObjectComponent.hpp"
#include "Vector2D.hpp"

namespace SpaceShipGame
{
    class PositionComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<PositionComponent>;

        PositionComponent();
        virtual ~PositionComponent();

        Vector2D& GetPosition() { return m_Position; };
        const Vector2D& GetPosition() const { return m_Position; }

        void SetPosition(const Vector2D& InPosition) { m_Position = InPosition; }

    private:
        Vector2D m_Position;
    };
}