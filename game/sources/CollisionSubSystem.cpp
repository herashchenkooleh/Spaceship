#include "ssg/CollisionSubSystem.hpp"
#include "ssg/CollisionComponent.hpp"

namespace ssg
{
    CollisionSubSystem::CollisionSubSystem()
    {

    }

    /*virtual*/ CollisionSubSystem::~CollisionSubSystem() = default;

    /*virtual*/ bool CollisionSubSystem::Initialize() /*override*/
    {
        return true;
    }

    /*virtual*/ void CollisionSubSystem::Update(const float InDeltaTime) /*override*/
    {
        decltype(auto) AsteroidsLayer = m_Components[CollisionComponent::Layer::Asteroid];
        decltype(auto) BulletLayer = m_Components[CollisionComponent::Layer::Bullet];

        for (const auto [BulletKey, BulletColliable]: BulletLayer)
        {
            if (!BulletColliable)
            {
                continue;
            }

            for (const auto [AsteroidKey, AsteroidColliable]: AsteroidsLayer)
            {
                if (!AsteroidColliable)
                {
                    continue;
                }

                CollisionComponent::Manifold Man = BulletColliable->Intersect(AsteroidColliable);
                if (Man.m_Collidig)
                {
                    BulletColliable->Callcalbacks();
                    AsteroidColliable->Callcalbacks();

                    break;
                }
            }
        }
    }

    /*virtual*/ void CollisionSubSystem::Deinitialize() /*override*/
    {
        
    }

    /*virtual*/ void CollisionSubSystem::RegisterGameObject(GameObject::Ptr InObject) /*override*/
    {
        if (CollisionComponent::Ptr CComponent = InObject->GetComponent<CollisionComponent>())
        {
            m_Components[CComponent->GetLayer()].insert({ CComponent->GetID(), CComponent });
            CComponent->SetOnCollisionEnter([InObject](){ InObject->MarkForDelete(); });
        }
    }

    /*virtual*/ void CollisionSubSystem::UnregisterGameObject(GameObject::Ptr InObject) /*override*/
    {
        if (CollisionComponent::Ptr CComponent = InObject->GetComponent<CollisionComponent>())
        {
            m_Components[CComponent->GetLayer()].erase(CComponent->GetID());
        }
    }
}