#include "ssg/ShellGameState.hpp"

namespace ssg
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

     /*virtual*/ GameStateBase::Handle ShellGameState::GetHandle() const
    {
        return s_ShellHandle;
    }
}
