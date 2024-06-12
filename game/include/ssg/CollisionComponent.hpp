#pragma once

#include "ssg/GameObject.hpp"
#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class CollisionComponent : public GameObjectComponent
    {
    public:
        using OnCollisionEnter = Function<void()>;

        enum class Layer : int
        {
            Default,
            Asteroid,
            Bullet,
            Planet,
            Character
        };

        using Ptr = SharedPtr<CollisionComponent>;

        struct Manifold
        {
            bool m_Collidig = false;
            CollisionComponent::Ptr m_Other = nullptr;
        };

        CollisionComponent(const Layer InLayer);
        ~CollisionComponent();

        Manifold Intersect(CollisionComponent::Ptr InOther);
        void Resolve(const Manifold& InManifold);

        Layer GetLayer() const { return m_Layer; }
        void SetLayer(const Layer InLayer) { m_Layer = InLayer; }

        void SetOnCollisionEnter(OnCollisionEnter InCallback) { m_Callback = InCallback; };
        void Callcalbacks() { m_Callback(); };

        FloatRect GetColliables() const;

    private:
        Layer m_Layer;
        OnCollisionEnter m_Callback;
    };
}