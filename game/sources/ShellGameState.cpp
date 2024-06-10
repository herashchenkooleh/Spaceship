#include "ssg/ShellGameState.hpp"
#include "ssg/ShellGameStateScript.hpp"
#include "ssg/SpawnGameObject.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"

namespace ssg
{

    /*static*/ bool ShellGameState::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<ShellGameState>("ShellGameState",  sol::base_classes, sol::bases<GameStateBase>());
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

    GameStateBase::Handle ShellGameState::s_ShellHandle = 0;

    ShellGameState::ShellGameState() = default;

    ShellGameState::~ShellGameState() = default;

    /*virtual*/ bool ShellGameState::Initialize() /*override*/
    {
        return true;
    }

    /*virtual*/ bool ShellGameState::Enter() /*override*/
    {
        bool Status = GameStateBase::Enter();

        ShellGameStateScript Script = { SharedFromThis(this) };
        Status = Script.Execute(m_ScriptFilePath);

        return Status;
    }

    /*virtual*/ void ShellGameState::Update() /*override*/
    {

    }

    /*virtual*/ void ShellGameState::Exit() /*override*/
    {

    }

    /*virtual*/ void ShellGameState::HandleInput(const InputEvent& InEvent) /*override*/
    {

    }

     /*virtual*/ GameStateBase::Handle ShellGameState::GetHandle() const
    {
        return s_ShellHandle;
    }
}
