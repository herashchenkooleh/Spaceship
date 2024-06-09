#include "ssg/ShellGameState.hpp"
#include "ssg/SpawnGameObject.hpp"

namespace ssg
{
    GameStateBase::Handle ShellGameState::s_ShellHandle = 0;

    ShellGameState::ShellGameState(const String& InGameStateFilePath)
        : GameStateBase(InGameStateFilePath, { InputEvent::Type::WindowResized })
    {
        
    }

    ShellGameState::~ShellGameState() = default;

    /*virtual*/ bool ShellGameState::Initialize() /*override*/
    {
        return true;
    }

    /*virtual*/ bool ShellGameState::Enter() /*override*/
    {
        m_Background = SpawnGameObject<Pawn>("assets/MainMenuBackground.jpeg");
        return true;
    }

    /*virtual*/ void ShellGameState::Update() /*override*/
    {

    }

    /*virtual*/ void ShellGameState::Exit() /*override*/
    {
        m_Background.reset();
    }

    /*virtual*/ void ShellGameState::HandleInput(const InputEvent& InEvent) /*override*/
    {

    }

     /*virtual*/ GameStateBase::Handle ShellGameState::GetHandle() const
    {
        return s_ShellHandle;
    }
}
