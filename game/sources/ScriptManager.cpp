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

namespace ssg
{
    /*static*/ String ScriptManager::s_DefaultContentName = "global";

    struct ScriptManager::Implementation
    {
        Map<String, SharedPtr<sol::state>> m_States;
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
            decltype(auto) LuaState = MakeShared<sol::state>();
            LuaState->open_libraries(sol::lib::base, sol::lib::string, sol::lib::math);
            m_Implementation->m_States.insert( { s_DefaultContentName, LuaState });

            //TODO need refactor
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

            LuaState->set_function("SpawnGameObject", []() -> GameObject::Ptr { return SpawnGameObject<GameObject>(); });
            LuaState->set_function("SpawnPawnObject", [](const String& InFilePat, const Transform& InTransform) -> Pawn::Ptr { return SpawnGameObject<Pawn>(InFilePat, InTransform); });
            LuaState->set_function("GetWindowSize", []() -> Vector2D { return GameEngine::GetInstance().GetWindowSize(); });

        }
        catch(...)
        {
            return false;
        }

        return true;
    }

    bool ScriptManager::AddNewScriptContent(const String& InContentName)
    {
        if (InContentName == s_DefaultContentName)
        {
            return true;
        }

        m_Implementation->m_States.insert( { InContentName, MakeShared<sol::state>() });

        return true;
    }

    ScriptManager::ScriptContentHandle ScriptManager::GetScriptContent(const String& InContentName /*= s_DefaultContentName*/)
    {
        if (auto Itr = m_Implementation->m_States.find(InContentName); Itr != m_Implementation->m_States.end())
        {
            return reinterpret_cast<void*>(Itr->second.get());
        }

        return nullptr;
    }

    void ScriptManager::DeleteScriptContent(const String& InContentName)
    {
        if (InContentName == s_DefaultContentName)
        {
            return;
        }

        m_Implementation->m_States.erase(InContentName);
    }
}