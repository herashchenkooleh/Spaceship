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
                                                        &Objective::m_Name,
                                                        sol::meta_function::index,
	                                                    &Objective::DynamicGet,
	                                                    sol::meta_function::new_index,
	                                                    &Objective::DynamicSet,
	                                                    sol::meta_function::length,
	                                                    [](Objective& InObj) { return InObj.m_Entries.size(); });        
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
        std::cout << "Condtract" << std::endl;
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

    void Objective::DynamicSet(const String& InKey, ScriptStackObject InValue)
    {
		auto Itr = m_Entries.find(InKey);
		if (Itr == m_Entries.cend())
        {
		    m_Entries.insert(Itr, { Move(InKey), Move(InValue) });
		}
		else
        {
			Pair<const String, ScriptObject>& KVP = *Itr;
			ScriptObject& Entry = KVP.second;
			Entry = ScriptObject(Move(InValue));
		}
	}

	ScriptObject Objective::DynamicGet(const String& InKey)
    {
		auto Itr = m_Entries.find(InKey);
		if (Itr == m_Entries.cend())
        {
			return ScriptNilObject;
		}
		return Itr->second;
	}
}