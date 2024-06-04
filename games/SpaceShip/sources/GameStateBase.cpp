#include "GameStateBase.hpp"

namespace SpaceShipGame
{
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
}
