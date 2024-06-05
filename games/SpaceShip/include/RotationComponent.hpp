#pragma once

#include "GameObjectComponent.hpp"

namespace SpaceShipGame
{
    class RotationComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<RotationComponent>;

        RotationComponent();
        ~RotationComponent();

        void SetDegrees(const float InDegrees) { m_Degrees = InDegrees; };
        float GetDegrees() const { return m_Degrees; };

    private:
        float m_Degrees;
    };
}