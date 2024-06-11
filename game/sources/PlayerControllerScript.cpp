#include "ssg/PlayerControllerScript.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"

namespace ssg
{
    PlayerControllerScript::PlayerControllerScript(PlayerController::Ptr InPlayerContoller)
        : m_PlayerContoller(InPlayerContoller)
    {

    }
    /*virtual*/ PlayerControllerScript::~PlayerControllerScript() = default;

    /*virtual*/ bool PlayerControllerScript::Execute(const String& InFilePath) /*override*/
    {
        if (!m_PlayerContoller)
        {
            return false;
        }

        if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
        {
            if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
            {  
                if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                {
                    SState->set("g_player_controller", m_PlayerContoller);
                    decltype(auto) Status = SState->do_file(InFilePath);
                    return true;
                }
            }
        }

        return false;
    }
}