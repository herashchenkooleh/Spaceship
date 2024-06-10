#pragma once

#include "ssg/GameObject.hpp"
#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class CollisionComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<CollisionComponent>;

        struct Manifold
        {
            bool m_Collidig = false;
            CollisionComponent::Ptr m_Other = nullptr;
        };

        CollisionComponent();
        ~CollisionComponent();

        Manifold Intersect(CollisionComponent::Ptr InOther);
        void Resolve(const Manifold& InManifold);

        const FloatRect& GetCollidable() const { return m_Collidables; };

    private:
        FloatRect m_Collidables;
    };
}