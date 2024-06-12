#pragma once

#include "ssg/Projectile.hpp"

namespace ssg
{
    class Weapon
    {
    public:
        using Ptr = SharedPtr<Weapon>;

        Weapon(GameObject* InOwner,const std::string& InBulletMesh, const int InBulletsLayer, const float InBulletSpeed = 50.0f);
        ~Weapon();

        void Shoot();

        static bool RegisterScriptType();

    private:
        float m_BulletSpeed;
        String m_BulletMesh;
        int m_BulletsLayer;
        GameObject* m_Owner;
    };
}