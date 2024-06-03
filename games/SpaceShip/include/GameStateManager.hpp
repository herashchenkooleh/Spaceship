#pragma once

#include "Configs.hpp"

namespace SpaceShipGame
{
    class GameStateManager
    {
    public:
        using Ptr = SharedPtr<GameStateManager>;

        GameStateManager();
        ~GameStateManager();
    };
}