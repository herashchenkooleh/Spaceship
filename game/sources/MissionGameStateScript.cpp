#include "ssg/MissionGameStateScript.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"

namespace ssg
{
    MissionGameStateScript::MissionGameStateScript(MissionGameState::Ptr InMissionState)
        : m_Mission(InMissionState)
    {

    }

    /*virtual*/ MissionGameStateScript::~MissionGameStateScript() = default;

    /*virtual*/ bool MissionGameStateScript::Execute(const String& InFilePath) /*override*/
    {
        if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
        {
            if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
            {  
                if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                {
                    SState->do_file(InFilePath);

                    m_Mission->m_LevelFilePath = SState->get<MissionGameState>("mission").m_LevelFilePath;
                    m_Mission->m_NumberObjectives = SState->get<MissionGameState>("mission").m_NumberObjectives;
                    m_Mission->m_PlayerControllerScript = SState->get<MissionGameState>("mission").m_PlayerControllerScript;
                    m_Mission->m_Objectives = SState->get<MissionGameState>("mission").m_Objectives;

                    return true;
                }
            }
        }

        return false;
    }
}