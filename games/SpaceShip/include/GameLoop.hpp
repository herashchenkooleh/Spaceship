#pragma once

#include "Configs.hpp"
#include "GameWindow.hpp"
#include "World.hpp"

namespace SpaceShipGame
{
    class GameLoop : public InputListener, public EnableSharedFromThis<GameLoop>
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

        bool Initialize(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager, World::Ptr InPlayWorld);
        void Start();
        void Deinitialize();

        virtual void HandleInput(const InputEvent& InEvent) override;

    private:
        ImplementationPtr m_Implementation;
    };
}