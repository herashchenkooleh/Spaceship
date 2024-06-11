#include "ssg/Object.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"  

namespace ssg
{
    Object::Identifier Object::s_Counter = 0;

    /*static*/ bool Object::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<Object>("Object", sol::constructors<Object()>(),
                                                     "id", sol::readonly_property(&Object::m_ID),
                                                     sol::meta_function::index,
	                                                 &Object::DynamicGet,
	                                                 sol::meta_function::new_index,
	                                                 &Object::DynamicSet,
	                                                 sol::meta_function::length,
	                                                 [](Object& InObj) { return InObj.m_Entries.size(); });
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

    Object::Object()
        : m_ID(s_Counter++)
    {

    }

    /*virtual*/ Object::~Object() = default;

    void Object::DynamicSet(const String& InKey, ScriptStackObject InValue)
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

	ScriptObject Object::DynamicGet(const String& InKey)
    {
		auto Itr = m_Entries.find(InKey);
		if (Itr == m_Entries.cend())
        {
			return ScriptNilObject;
		}
		return Itr->second;
	}
}