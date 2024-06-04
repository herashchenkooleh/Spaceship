#include "MissionGameState.hpp"

namespace SpaceShipGame
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
        return true;
    }

    /*virtual*/ void MissionGameState::Update() /*override*/
    {

    }

    /*virtual*/ void MissionGameState::Exit() /*override*/
    {
        
    }

    /*virtual*/ void MissionGameState::HandleInput(const InputEvent& InEvent) /*override*/
    {

    }
}
