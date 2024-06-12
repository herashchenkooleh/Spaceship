#pragma once

#include "ssg/Projectile.hpp"

namespace ssg
{
    class Weapon
    {
    public:
        Weapon(GameObject::Ptr InOwner);
        ~Weapon();

        Projectile::Ptr Shoot();

    private:
        GameObject::Ptr m_Owner;
    };
}