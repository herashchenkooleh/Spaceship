#include "ssg/ScriptManager.hpp"
#include "sol/sol.hpp"

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
            m_Implementation->m_States.insert( { s_DefaultContentName, MakeShared<sol::state>() });

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