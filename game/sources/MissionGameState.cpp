#include "ssg/World.hpp"
#include "ssg/MissionGameState.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"

namespace ssg
{
    class MissionGameStateScriptTypeBuilder
    {
    public:
        MissionGameStateScriptTypeBuilder()
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
                //TODO
            }
        }
    };

    static MissionGameStateScriptTypeBuilder s_ScriptTypeInitializer;
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
        // try
        // {
        //     MissionGameStateScriptBuilder Buildr = { m_GameStateFilePath, SharedFromThis<MissionGameState>(this)};
        //     return Buildr.ExecuteScript();
        // }
        // catch(...)
        // {
        //     //TODO
        // }
        return false;
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
