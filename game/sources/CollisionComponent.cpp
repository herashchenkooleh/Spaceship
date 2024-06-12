#include "ssg/CollisionComponent.hpp"
#include "ssg/Transform.hpp"
#include "ssg/TransformComponent.hpp"
#include <cmath>

namespace ssg
{   
    CollisionComponent::CollisionComponent(const Layer InLayer)
        : m_Layer(InLayer)
    {

    }
    
    CollisionComponent::~CollisionComponent() = default;

    CollisionComponent::Manifold CollisionComponent::Intersect(CollisionComponent::Ptr InOther)
    {
        Manifold Result;
        // if (m_Collidables.findIntersection(InOther->m_Collidables))
        // {
        //     Result.m_Collidig = true;
        //     Result.m_Other = InOther;
        // }

        return Result;
    }

    void CollisionComponent::Resolve(const Manifold& InManifold)
    {
        // // auto transform = owner->transform;
        
        // // if(transform->isStatic()) { return; }
        
        // const FloatRect& Rect1 = GetCollidable();
        // const sf::FloatRect& Rect2 = InManifold.m_Other->GetCollidable();
        
        // if(!Rect1.findIntersection(Rect2))
        // {
        //     return;
        // }
        
        // float Resolve = 0;
        // float XDiff = (Rect1.left + (Rect1.width * 0.5f)) - (Rect2.left + (Rect2.width * 0.5f));
        // float YDiff = (Rect1.top + (Rect1.height * 0.5f)) - (Rect2.top + (Rect2.height * 0.5f));
        
        // if (std::fabs(XDiff) > std::fabs(YDiff))
        // {
        //     if (XDiff > 0)
        //     {
        //         Resolve = (Rect2.left + Rect2.width) - Rect1.left;
        //     }
        //     else
        //     {
        //         Resolve = -((Rect1.left + Rect1.width) - Rect2.left);
        //     }
            
        //     if (TransformComponent::Ptr TComponent = GetComponent<TransformComponent>())
        //     {
        //         decltype(auto) CurrentTransform = TComponent->GetTransform();
        //         CurrentTransform.AddPosition({ Resolve, 0 });
        //     }
        // }
        // else
        // {
        //     if (YDiff > 0)
        //     {
        //         Resolve = (Rect2.top + Rect2.height) - Rect1.top;
        //     }
        //     else
        //     {
        //         Resolve = -((Rect1.top + Rect1.height) - Rect2.top);
        //     }
        //     if (TransformComponent::Ptr TComponent = GetComponent<TransformComponent>())
        //     {
        //         decltype(auto) CurrentTransform = TComponent->GetTransform();
        //         CurrentTransform.AddPosition({ 0, Resolve });
        //     }
        // }
    }
}