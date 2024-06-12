#include "ssg/Weapon.hpp"
#include "ssg/SpawnGameObject.hpp"
#include "ssg/Transform.hpp"
#include "ssg/TransformComponent.hpp"
#include "ssg/MoveComponent.hpp"

namespace ssg
{
    Weapon::Weapon(GameObject::Ptr InOwner)
        : m_Owner(InOwner)
    {

    }

    Weapon::~Weapon() = default;

    Projectile::Ptr Weapon::Shoot()
    {
        if (!m_Owner)
        {
            return nullptr;
        }

        if (decltype(auto) TComponent = m_Owner->GetComponent<TransformComponent>())
        {
            if (decltype(auto) MComponent = m_Owner->GetComponent<MoveComponent>())
            {
                Projectile::Ptr Bullet = SpawnGameObject<Projectile>("rocket.png", TComponent->GetTransform());

                Bullet->SetAcceleration(MComponent->GetLookAt());
                Bullet->SetSpeed(50.0f);
            }
        }

        return nullptr;
    }
}