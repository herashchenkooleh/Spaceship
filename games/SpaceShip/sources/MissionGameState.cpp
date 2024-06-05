#include "World.hpp"
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
        m_Character = MakeShared<Character>("assets/ship.png");

        return true;
    }

    /*virtual*/ bool MissionGameState::Enter() /*override*/
    {
        
        World::GetCurrentWorld()->RegisterGameObject(m_Character);

        return true;
    }

    /*virtual*/ void MissionGameState::Update() /*override*/
    {

    }

    /*virtual*/ void MissionGameState::Exit() /*override*/
    {
        m_Character->MarkForDelete();
    }

    /*virtual*/ void MissionGameState::HandleInput(const InputEvent& InEvent) /*override*/
    {

    }

    /*virtual*/ GameStateBase::Handle MissionGameState::GetHandle() const
    {
        return s_MissionHandle;
    }
}
