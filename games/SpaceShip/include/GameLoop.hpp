#pragma once

#include "Configs.hpp"
#include "GameWindow.hpp"
#include "InputManager.hpp"

namespace SpaceShipGame
{
    class GameLoop
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<GameLoop>;

    public:
        GameLoop();
        ~GameLoop();

        GameLoop(const GameLoop& InObj) = delete;
        GameLoop& operator=(const GameLoop& InObj) = delete;

        bool Initialize(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager);
        void Start();
        void Deinitialize();

    private:
        ImplementationPtr m_Implementation;
    };
}