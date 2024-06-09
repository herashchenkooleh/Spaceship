#include "ssg/World.hpp"
#include "ssg/MissionGameState.hpp"
#include "ssg/MissionGameStateScriptBuilder.hpp"

namespace ssg
{
    GameStateBase::Handle MissionGameState::s_MissionHandle = 1;

    MissionGameState::MissionGameState()
    {

    }

    MissionGameState::~MissionGameState() = default;

    /*virtual*/ bool MissionGameState::Initialize() /*override*/
    {
        return true;
    }

    /*virtual*/ bool MissionGameState::Enter() /*override*/
    {
        try
        {
            MissionGameStateScriptBuilder Buildr = {"assets/DefaultMissionGameState.lua", SharedFromThis<MissionGameState>(this)};
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

    }

    /*virtual*/ void MissionGameState::Exit() /*override*/
    {

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
