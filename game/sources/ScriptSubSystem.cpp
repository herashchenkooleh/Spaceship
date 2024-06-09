#include "ssg/ScriptSubSystem.hpp"

namespace ssg
{
    ScriptSubSystem::ScriptSubSystem()
        : m_Manager(nullptr)
    {

    }

    /*virtual*/ ScriptSubSystem::~ScriptSubSystem() = default;

    /*virtual*/ bool ScriptSubSystem::Initialize() /*override*/
    {
        try
        {
            m_Manager = MakeShared<ScriptManager>();
            if(!m_Manager || !m_Manager->Initialize())
            {
                return false;
            }
        }
        catch(...)
        {
            return false;
        }

        return true;
    }

    /*virtual*/ void ScriptSubSystem::Update(const float InDeltaTime) /*override*/
    {

    }
    
    /*virtual*/ void ScriptSubSystem::Deinitialize() /*override*/
    {

    }
}