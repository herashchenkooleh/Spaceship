#include "ssg/PhysicComponent.hpp"
#include "SFML/Graphics.hpp"

namespace ssg
{
    struct PhysicComponent::Implementation
    {
        GameObject::Ptr m_Parent;

        //How obtain from render?
        sf::FloatRect m_Rect;

        Implementation(GameObject::Ptr InParent);
        ~Implementation();
    };

    PhysicComponent::Implementation::Implementation(GameObject::Ptr InParent)
        : m_Parent(InParent)
    {

    }

    PhysicComponent::Implementation::~Implementation() = default;
    

    PhysicComponent::PhysicComponent(GameObject::Ptr InParent)
        : m_Implementation(MakeShared<Implementation>(InParent))
    {

    }
    
    PhysicComponent::~PhysicComponent() = default;

    PhysicComponent::Manifold PhysicComponent::Intersect(PhysicComponent::Ptr InOther)
    {
        Manifold Result;
        auto IntersectionRect = m_Implementation->m_Rect.findIntersection(InOther->m_Implementation->m_Rect);
        if (IntersectionRect)
        {
            Result.m_Collidig = true;
            Result.m_Other = InOther;
        }

        return Result;
    }

    void PhysicComponent::Resolve(const Manifold& InManifold)
    {

    }
}