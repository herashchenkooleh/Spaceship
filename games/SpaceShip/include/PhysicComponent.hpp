#pragma once

#include "GameObjectComponent.cpp"

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