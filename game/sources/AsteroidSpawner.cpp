#include "ssg/AsteroidSpawner.hpp"
#include "ssg/Projectile.hpp"
#include "ssg/SpawnGameObject.hpp"
#include "ssg/TransformComponent.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"  

namespace ssg
{
    /*static*/ bool AsteroidSpawner::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<AsteroidSpawner>("AsteroidSpawner", sol::constructors<AsteroidSpawner(const String&, const float, const float)>(), sol::base_classes, sol::bases<GameObject>(),
                                                               "AddTarget", &AsteroidSpawner::AddTarget,
                                                               "RemoveTarget", &AsteroidSpawner::RemoveTarget);
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

    AsteroidSpawner::AsteroidSpawner(const String& InAsteroidsMesh, const float InAsteroidsSpeed, const float InSpawnInterval)
        : m_AccumulatedTime(0.0f)
        , m_SideSelect(1, 4)
        , m_PositionXSelect(0.0f, GameEngine::GetInstance().GetWindowSize().GetX())
        , m_PositionYSelect(0.0f, GameEngine::GetInstance().GetWindowSize().GetY())
        , m_TargetSelect(0, 0)
        , m_AsteroidsMesh(InAsteroidsMesh)
        , m_AsteroidsSpeed(InAsteroidsSpeed)
        , m_SpawnInterval(InSpawnInterval)
    {
    }
    
    /*virtual*/ AsteroidSpawner::~AsteroidSpawner() = default;

    /*virtual*/ void AsteroidSpawner::Update(const float InDeltaTime) /*override*/
    {
        m_AccumulatedTime += InDeltaTime;
        if (m_AccumulatedTime >= m_SpawnInterval)
        {
            m_AccumulatedTime = 0.0f;
            Transform AsteroidTransform;

            size_t Side = m_SideSelect.Get();

            if (Side == 1)
            {
                AsteroidTransform.SetPosition({ 0.0f, m_PositionYSelect.Get() });
            }
            else if (Side == 2)
            {
                AsteroidTransform.SetPosition({ m_PositionXSelect.Get(), 0.0f });
            }
            else if (Side == 3)
            {
                AsteroidTransform.SetPosition({ GameEngine::GetInstance().GetWindowSize().GetX(), m_PositionYSelect.Get() });
            }
            else
            {
                AsteroidTransform.SetPosition({ m_PositionXSelect.Get(), GameEngine::GetInstance().GetWindowSize().GetY() });
            }

            AsteroidTransform.SetRotation(0.0f);
            AsteroidTransform.SetOrigin({0.5, 0.5});
            AsteroidTransform.SetSize({ 50.0f, 50.f });

            size_t Target = m_TargetSelect.Get();
            if (Target >= m_Targets.size())
            {
                return;
            }
            
            decltype(auto) TargetItr = std::next(m_Targets.begin(), Target);
            if (TargetItr == m_Targets.end())
            {
                return;
            }
            if(decltype(auto) TrComponent =  TargetItr->second->GetComponent<TransformComponent>())
            {
                Projectile::Ptr Asteroid = SpawnGameObject<Projectile>(m_AsteroidsMesh, AsteroidTransform);
                Asteroid->SetSpeed(m_AsteroidsSpeed); //TODO
                decltype(auto) Direction = TrComponent->GetTransform().GetPosition() - AsteroidTransform.GetPosition();
                Direction.Normalize();
                Asteroid->SetAcceleration(Direction);
            }
        }
    }

    void AsteroidSpawner::AddTarget(Pawn::Ptr InTarget)
    {
        m_Targets.insert({InTarget->GetID(), InTarget});
        m_TargetSelect = Random<std::uniform_int_distribution<size_t>, size_t>{  0, m_Targets.size() };
    }
    
    void AsteroidSpawner::RemoveTarget(Pawn::Ptr InTarget)
    {
        m_Targets.erase(InTarget->GetID());
        m_TargetSelect = Random<std::uniform_int_distribution<size_t>, size_t>{  0, m_Targets.size()  };
    }
}