#include "ShellGameState.hpp"

namespace SpaceShipGame
{
    GameStateBase::Handle ShellGameState::s_ShellHandle = 0;

    ShellGameState::ShellGameState()
    {

    }

    ShellGameState::~ShellGameState() = default;

    /*virtual*/ bool ShellGameState::Initialize() /*override*/
    {
        return true;
    }

    /*virtual*/ bool ShellGameState::Enter() /*override*/
    {
        return true;
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
}
