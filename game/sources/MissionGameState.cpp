#include "ssg/World.hpp"
#include "ssg/MissionGameState.hpp"
#include "ssg/MissionGameStateScriptBuilder.hpp"

namespace ssg
{
    GameStateBase::Handle MissionGameState::s_MissionHandle = 1;

    MissionGameState::MissionGameState(const String& InGameStateFilePath)
        : GameStateBase(InGameStateFilePath, { InputEvent::Type::KeyReleased })
    {

    }

    MissionGameState::~MissionGameState() = default;

    /*virtual*/ bool MissionGameState::Initialize() /*override*/
    {
        return true;
    }

    /*virtual*/ bool MissionGameState::Enter() /*override*/
    {
        bool Status = GameStateBase::Enter();
        try
        {
            MissionGameStateScriptBuilder Buildr = { m_GameStateFilePath, SharedFromThis<MissionGameState>(this)};
            return Buildr.ExecuteScript();
        }
        catch(...)
        {
            //TODO
        }
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
