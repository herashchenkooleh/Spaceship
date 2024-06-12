#include "ssg/Weapon.hpp"
#include "ssg/SpawnGameObject.hpp"
#include "ssg/Transform.hpp"
#include "ssg/TransformComponent.hpp"
#include "ssg/MoveComponent.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"
#include "ssg/GameObject.hpp"

namespace ssg
{
    /*static*/ bool Weapon::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<Weapon>("Weapon", "bullet_speed", &Weapon::m_BulletSpeed,
                                                               "bullet_mesh", &Weapon::m_BulletMesh);
                    }
                }
            }
        }
        catch(...)
        {
            return false;
        }

        return true;
    }

    Weapon::Weapon(GameObject* InOwner, const std::string& InBulletMesh, const int InBulletsLayer, const float InBulletSpeed /*= 50.0f*/)
        : m_BulletSpeed(InBulletSpeed)
        , m_BulletMesh(InBulletMesh)
        , m_Owner(InOwner)
        , m_BulletsLayer(InBulletsLayer)
    {

    }

    Weapon::~Weapon() = default;

    void Weapon::Shoot()
    {
        if (!m_Owner)
        {
            return;
        }

        if (decltype(auto) TComponent = m_Owner->GetComponent<TransformComponent>())
        {
            Projectile::Ptr Bullet = SpawnGameObject<Projectile>(m_BulletMesh, TComponent->GetTransform(), m_BulletsLayer);

            Bullet->SetAcceleration(m_Owner->GetComponent<MoveComponent>()->GetLookAt());
            Bullet->SetSpeed(m_BulletSpeed);
        }
    }
}