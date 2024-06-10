#pragma once

#include "ssg/GameObject.hpp"
#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class PhysicComponent : public GameObjectComponent
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<PhysicComponent>;

        struct Manifold
        {
            bool m_Collidig = false;
            PhysicComponent::Ptr m_Other = nullptr;
        };

        PhysicComponent(GameObject::Ptr InParent);
        ~PhysicComponent();

        Manifold Intersect(PhysicComponent::Ptr InOther);
        void Resolve(const Manifold& InManifold);

    private:
        ImplementationPtr m_Implementation;
    };
}