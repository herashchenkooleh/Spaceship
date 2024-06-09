#include "ssg/ScriptSubSystem.hpp"

namespace ssg
{
    ScriptSubSystem::ScriptSubSystem()
    {

    }

    /*virtual*/ ScriptSubSystem::~ScriptSubSystem() = default;

    /*virtual*/ bool ScriptSubSystem::Initialize() /*override*/
    {
        return true;
    }

    /*virtual*/ void ScriptSubSystem::Update(const float InDeltaTime) /*override*/
    {

    }
    
    /*virtual*/ void ScriptSubSystem::Deinitialize() /*override*/
    {

    }
}