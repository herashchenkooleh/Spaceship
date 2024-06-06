#pragma once

#include "GameObjectComponent.hpp"

namespace SpaceShipGame
{
    class PhysicComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<PhysicComponent>;

        PhysicComponent();
        ~PhysicComponent();
    };
}