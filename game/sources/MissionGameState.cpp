#include "ssg/MissionGameState.hpp"
#include "ssg/MissionGameStateScript.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"  

namespace ssg
{
    /*static*/ bool MissionGameState::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<MissionGameState>("MissionGameState", sol::base_classes, sol::bases<GameStateBase>(),
                                                               "number_objectives", &MissionGameState::m_NumberObjectives,
                                                               "player_controller", &MissionGameState::m_PlayerControllerScript,
                                                               "objectives",        &MissionGameState::m_Objectives);
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

    GameStateBase::Handle MissionGameState::s_MissionHandle = 1;

    MissionGameState::MissionGameState() = default;

    MissionGameState::~MissionGameState() = default;

    /*virtual*/ bool MissionGameState::Initialize() /*override*/
    {
        return true;
    }

    /*virtual*/ bool MissionGameState::Enter() /*override*/
    {
        bool Status = GameStateBase::Enter();
        if (!Status)
        {
            return false;
        }

        MissionGameStateScript Script = { SharedFromThis(this) };
        Status = Script.Execute(m_ScriptFilePath);

        return Status;
    }

    /*virtual*/ void MissionGameState::Update() /*override*/
    {
        GameStateBase::Update();
    }

    /*virtual*/ void MissionGameState::Exit() /*override*/
    {
        GameStateBase::Exit();
    }

    /*virtual*/ void MissionGameState::HandleInput(const InputEvent& InEvent) /*override*/
    {
        // if ((InEvent.GetType() == InputEvent::Type::KeyReleased) && ())
        // {

        // }
    }

    /*virtual*/ GameStateBase::Handle MissionGameState::GetHandle() const
    {
        return s_MissionHandle;
    }
}
