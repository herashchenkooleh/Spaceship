#pragma once

#include "ssg/Global.hpp"
#include "ssg/QuadTree.hpp"
#include "ssg/PhysicComponent.hpp"

namespace ssg
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

        Vector<PhysicComponent> m_Components;
    };
}