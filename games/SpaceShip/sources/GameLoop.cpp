#include "GameLoop.hpp"

namespace SpaceShipGame
{
    struct GameLoop::Implementation
    {
        bool m_Exit;
        GameWindow::Ptr m_Window;
        InputManager::Ptr m_InputManager;
        World::Ptr m_PlayWorld;

        Implementation(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager, World::Ptr InPlayWorld);
        ~Implementation();
    };

    GameLoop::Implementation::Implementation(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager, World::Ptr InPlayWorld)
        : m_Exit(false)
        , m_Window(InWindow)
        , m_InputManager(InInputManager)
        , m_PlayWorld(InPlayWorld)
    {
    }

    GameLoop::Implementation::~Implementation() = default;

    GameLoop::GameLoop()
        : m_Implementation(nullptr)
    {
    }

    GameLoop::~GameLoop() = default;

    bool GameLoop::Initialize(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager, World::Ptr InPlayWorld)
    {
        if (m_Implementation)
        {
            return true;
        }

        try
        {
            m_Implementation = MakeShared<Implementation>(InWindow, InInputManager, InPlayWorld);
            m_Implementation->m_InputManager->Register(InputEvent::Type::Exit, SharedFromThis(this));
        }
        catch (...)
        {
            return false;
        }

        return true;
    }

    void GameLoop::Start()
    {
        if (!m_Implementation ||
            !m_Implementation->m_Window ||
            !m_Implementation->m_InputManager ||
            !m_Implementation->m_PlayWorld)
        {
            return;
        }

        while (!m_Implementation->m_Exit)
        {
            m_Implementation->m_InputManager->Update();
            m_Implementation->m_PlayWorld->Update();
        }
    }

    void GameLoop::Deinitialize()
    {
        m_Implementation->m_Window->Close();
    }

    /*virtual*/ void GameLoop::HandleInput(const InputEvent& InEvent) /*override*/
    {
        
    }
}