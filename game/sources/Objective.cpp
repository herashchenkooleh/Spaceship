#include "ssg/Objective.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"

namespace ssg
{
    /*static*/ bool Objective::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<Objective>("Objective", sol::constructors<Objective()>(),
                                                        "Update", 
                                                        &Objective::m_Function,
	                                                    "name",
                                                        &Objective::m_Name);        
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

    Objective::Objective()
    {
        if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
        {
            if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
            {
                if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                {
                    m_Function = sol::make_reference<sol::function>(SState->lua_state(), &Objective::Update);
                }
            }
        }
    }

    Objective::~Objective() = default;

    Objective::Objective(const Objective& InObj)
        : m_Name(InObj.m_Name)
        , m_Function(InObj.m_Function)
    {

    }

    Objective& Objective::operator=(const Objective& InObj)
    {
        if (this != &InObj)
        {
            m_Name = InObj.m_Name;
            m_Function = InObj.m_Function;
        }

        return *this;
    }

    bool Objective::Initialize()
    {
        return true;
    }

    void Objective::Update()
    {
        m_Function.call();
    }    
}