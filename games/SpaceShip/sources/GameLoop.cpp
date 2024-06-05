#include "GameLoop.hpp"
#include "Timer.hpp"
#include "Renderer.hpp"
#include <iostream>

namespace SpaceShipGame
{
    struct GameLoop::Implementation : public InputListener
    {
        bool m_Exit;
        GameWindow::Ptr m_Window;
        InputManager::Ptr m_InputManager;
        World::Ptr m_PlayWorld;
        Timer m_Timer;
        Renderer::Ptr m_Renderer;

        Implementation(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager, World::Ptr InPlayWorld);
        ~Implementation();

        virtual void HandleInput(const InputEvent& InEvent) override;
    };

    GameLoop::Implementation::Implementation(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager, World::Ptr InPlayWorld)
        : m_Exit(false)
        , m_Window(InWindow)
        , m_InputManager(InInputManager)
        , m_PlayWorld(InPlayWorld)
        , m_Renderer(nullptr)
    {
    }

    GameLoop::Implementation::~Implementation() = default;

    /*virtual*/ void GameLoop::Implementation::HandleInput(const InputEvent& InEvent) /*override*/
    {
        m_Exit = true;
    }

    GameLoop::GameLoop()
        : m_Implementation(nullptr)
    {
    }

    GameLoop::~GameLoop() = default;

    bool GameLoop::Initialize(GameWindow::Ptr InWindow, InputManager::Ptr InInputManager, World::Ptr InPlayWorld, Renderer::Ptr InRenderer)
    {
        if (m_Implementation)
        {
            return true;
        }

        try
        {
            m_Implementation = MakeShared<Implementation>(InWindow, InInputManager, InPlayWorld);
            m_Implementation->m_InputManager->Register(InputEvent::Type::Exit, m_Implementation);

            m_Implementation->m_Renderer = InRenderer;
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

        long long TimeSinceLastUpdate = 0;
        long long TimeStamp = Timer::GetTimestempForFps(60);
        while (!m_Implementation->m_Exit)
        {
            TimeSinceLastUpdate += m_Implementation->m_Timer.Reset();

            Timer SubStepingTimer;
            do
            { 
                m_Implementation->m_InputManager->Update();
                m_Implementation->m_PlayWorld->Update(static_cast<float>(SubStepingTimer.Reset()) / static_cast<float>(Timer::GetTicksPerSecond()));
                TimeSinceLastUpdate -= TimeStamp;
            } while (TimeSinceLastUpdate > TimeStamp);
            

            float Interpolation = 0.2; //TODO
            m_Implementation->m_Renderer->Draw(Interpolation);
            
        }
    }

    void GameLoop::Deinitialize()
    {
        m_Implementation->m_Window->Close();
    }
}