#include "ssg/ScriptManager.hpp"
#include "sol/sol.hpp"

#include "ssg/GameStateBase.hpp"
#include "ssg/ShellGameState.hpp"
#include "ssg/MissionGameState.hpp"
#include "ssg/Level.hpp"
#include "ssg/Objective.hpp"
#include "ssg/Vector2D.hpp"
#include "ssg/Transform.hpp"

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
            LuaState->open_libraries();
            m_Implementation->m_States.insert( { s_DefaultContentName, LuaState });

            //TODO need refactor
            Vector2D::RegisterScriptType();
            Transform::RegisterScriptType();
            Object::RegisterScriptType();
            GameObject::RegisterScriptType();
            GameStateBase::RegisterScriptType();
            ShellGameState::RegisterScriptType();
            MissionGameState::RegisterScriptType();
            Level::RegisterScriptType();
            Objective::RegisterScriptType();

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