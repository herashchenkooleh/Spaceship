#pragma once

#include "Configs.hpp"
#include "GameStateManager.hpp"
#include "InputManager.hpp"

namespace SpaceShipGame
{
    class World
    {
    public:
        using Ptr = SharedPtr<World>;

        World();
        ~World();

        bool Initialize(InputManager::Ptr InInputManager);
        void Update();

    private:
        GameStateManager::Ptr m_StateManager;
        InputManager::Ptr m_InputManager;
    };
}