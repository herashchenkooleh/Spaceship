#include "ssg/ScriptManager.hpp"
#include "sol/sol.hpp"

#include "ssg/GameEngine.hpp"
#include "ssg/GameStateBase.hpp"
#include "ssg/ShellGameState.hpp"
#include "ssg/MissionGameState.hpp"
#include "ssg/Level.hpp"
#include "ssg/Objective.hpp"
#include "ssg/Vector2D.hpp"
#include "ssg/Transform.hpp"
#include "ssg/Pawn.hpp"
#include "ssg/PlayerController.hpp"
#include "ssg/SpawnGameObject.hpp"
#include "ssg/Weapon.hpp"
#include "ssg/AsteroidSpawner.hpp"

namespace ssg
{
    struct ScriptManager::Implementation
    {
        sol::state m_State;
    };

    ScriptManager::ScriptManager()
        : m_Implementation(nullptr)
    {

    }

    ScriptManager::~ScriptManager() = default;

    bool ScriptManager::Initialize()
    {
        if (m_Implementation)
        {
            return true;
        }

        try
        {
            m_Implementation = MakeShared<Implementation>();
            m_Implementation->m_State.open_libraries();

            Vector2D::RegisterScriptType();
            Transform::RegisterScriptType();
            Object::RegisterScriptType();
            GameObject::RegisterScriptType();
            Pawn::RegisterScriptType();
            GameStateBase::RegisterScriptType();
            ShellGameState::RegisterScriptType();
            MissionGameState::RegisterScriptType();
            Level::RegisterScriptType();
            Objective::RegisterScriptType();
            PlayerController::RegisterScriptType();
            Weapon::RegisterScriptType();
            AsteroidSpawner::RegisterScriptType();

            m_Implementation->m_State.set_function("SpawnAsteroidSpawner", [](const String& InFilePat, const float InSpeed, const float InInterval, const int InLayer) -> AsteroidSpawner::Ptr {  return SpawnGameObject<AsteroidSpawner>(InFilePat, InSpeed, InInterval, InLayer); });
            m_Implementation->m_State.set_function("SpawnPawnObject", [](const String& InFilePat, const Transform& InTransform, const int InLayer) -> Pawn::Ptr { return SpawnGameObject<Pawn>(InFilePat, InTransform, InLayer); });
            m_Implementation->m_State.set_function("SpawnCharacter", [](const String& InFilePat, const Transform& InTransform, const String& InBulletsMesh, const float InBulletsSpeed, const int InPawnLayer, const int InWeaponLayer) -> Pawn::Ptr { return SpawnGameObject<Pawn>(InFilePat, InTransform, InBulletsMesh, InBulletsSpeed, InPawnLayer, InWeaponLayer); });
            m_Implementation->m_State.set_function("GetWindowSize", []() -> Vector2D { return GameEngine::GetInstance().GetWindowSize(); });

        }
        catch(...)
        {
            return false;
        }

        return true;
    }

    ScriptManager::ScriptContentHandle ScriptManager::GetScriptContent()
    {
        return static_cast<ScriptContentHandle>(&(m_Implementation->m_State));
    }
}