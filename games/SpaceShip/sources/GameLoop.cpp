#include "GameLoop.hpp"

namespace SpaceShipGame
{
    struct GameLoop::Implementation
    {
        bool m_Exit;
        GameWindow::Ptr m_Window;
        InputManager::Ptr m_InputManager;

        Implementation(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager);
        ~Implementation();
    };

    GameLoop::Implementation::Implementation(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager)
        : m_Exit(false), m_Window(InWindow), m_InputManager(InInputManager)
    {
    }

    GameLoop::Implementation::~Implementation() = default;

    GameLoop::GameLoop()
        : m_Implementation(nullptr)
    {
    }

    GameLoop::~GameLoop() = default;

    bool GameLoop::Initialize(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager)
    {
        if (m_Implementation)
        {
            return true;
        }

        try
        {
            m_Implementation = MakeShared<Implementation>(InWindow, InInputManager);
        }
        catch (...)
        {
            return false;
        }

        return true;
    }

    void GameLoop::Start()
    {
        while (!m_Implementation->m_Exit)
        {
            InputEvent Event = m_Implementation->m_Window->PollEvent();

            m_Implementation->m_InputManager->HandleEvent(Event);

            switch (Event.GetType())
            {
            case InputEvent::Type::Exit:
                m_Implementation->m_Exit = true;
                break;

            default:
                break;
            }
        }
    }

    void GameLoop::Deinitialize()
    {
        m_Implementation->m_Window->Close();
    }
}