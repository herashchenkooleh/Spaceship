#include "ssg/ShellGameStateScript.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"

namespace ssg
{
    ShellGameStateScript::ShellGameStateScript(ShellGameState::Ptr InShellState)
        : m_ShellState(InShellState)
    {

    }

    /*virtual*/ ShellGameStateScript::~ShellGameStateScript() = default;

    /*virtual*/ bool ShellGameStateScript::Execute(const String& InFilePath) /*override*/
    {
        if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
        {
            if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
            {
                if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                {
                    SState->do_file(InFilePath);
                    m_ShellState->m_LevelFilePath = SState->get<ShellGameState>("state").m_LevelFilePath;
                    return true;
                }
            }
        }

        return false;
    }
}