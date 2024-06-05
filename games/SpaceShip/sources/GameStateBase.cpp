#include "GameStateBase.hpp"

namespace SpaceShipGame
{
    int GameStateBase::s_InvalidHandle = -1;

    GameStateBase::GameStateBase() = default;
    /*virtual*/ GameStateBase::~GameStateBase() = default;

    /*virtual*/ bool GameStateBase::Initialize()
    {
        return true;
    }

    /*virtual*/ bool GameStateBase::Enter()
    {
        return true;
    }

    /*virtual*/ void GameStateBase::Update()
    {

    }

    /*virtual*/ void GameStateBase::Exit()
    {

    }

    /*virtual*/ GameStateBase::Handle GameStateBase::GetHandle() const
    {
        return s_InvalidHandle;
    }
}
