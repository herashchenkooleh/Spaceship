#pragma once

#include "ssg/Global.hpp"
#include "ssg/GameWindow.hpp"
#include "ssg/World.hpp"

namespace ssg
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

        bool Initialize(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager, World::Ptr InPlayWorld, Renderer::Ptr InRenderer);
        void Start();
        void Deinitialize();

    private:
        ImplementationPtr m_Implementation;
    };
}