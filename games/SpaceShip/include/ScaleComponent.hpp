#pragma once

#include "Vector2D.hpp"
#include "GameObjectComponent.hpp"

namespace SpaceShipGame
{
    class ScaleComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<ScaleComponent>;

        ScaleComponent();
        ~ScaleComponent();

        void SetScale(const Vector2D& InScale) { m_Scale = InScale; };
        const Vector2D& GetScale() const { return m_Scale; };

    private:
        Vector2D m_Scale;
    };
}