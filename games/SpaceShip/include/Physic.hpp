#pragma once

#include "Configs.hpp"
#include "QuadTree.hpp"
#include "PhysicComponent.hpp"

namespace SpaceShipGame
{
    class Physic
    {
    public:
        using Ptr = SharedPtr<Physic>;

        Physic();
        ~Physic();

        Physic(const Physic& InObj) = delete;
        Physic& operator=(const Physic& InObj) = delete;

        bool Initialize();
        void Update(const float InDeltaTime);

        void Register(PhysicComponent::Ptr InComponent);
        void Unregister(PhysicComponent::Ptr InComponent);

    private:
        QuadTree m_Tree;

        Vector<PhysicComponent> 
    };
}