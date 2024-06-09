#include "ssg/GameLoop.hpp"
#include "ssg/Timer.hpp"
#include "ssg/Renderer.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/InputSubSystem.hpp"
#include "ssg/RenderSubSystem.hpp"
#include "ssg/World.hpp"

namespace ssg
{
    struct GameLoop::Implementation : public InputListener
    {
        bool m_Exit;
        Timer m_Timer;

        Implementation();
        ~Implementation();

        virtual void HandleInput(const InputEvent& InEvent) override;
    };

    GameLoop::Implementation::Implementation()
        : InputListener({ InputEvent::Type::Exit })
        , m_Exit(false)
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

    GameLoop::~GameLoop()
    {
        Deinitialize();
    }

    bool GameLoop::Initialize()
    {
        if (m_Implementation)
        {
            return true;
        }

        try
        {
            m_Implementation = MakeShared<Implementation>();
        }
        catch (...)
        {
            return false;
        }

        if (InputSubSystem::Ptr InpSubSystem = GameEngine::GetInstance().GetSubSystem<InputSubSystem>())
        {
            if(InputManager::Ptr InpManager = InpSubSystem->GetManager())
            {
                InpManager->Register(m_Implementation);
                return true;
            }
        }

        return false;
    }

    void GameLoop::Start()
    {
        World::Ptr GameWorld = MakeShared<World>();
        World::SetCurrentWorld(GameWorld);

        if (!GameWorld->Initialize())
        {
            return;
        }

        Renderer::Ptr RendererObject = nullptr;
        if (RenderSubSystem::Ptr RSubSystem = GameEngine::GetInstance().GetSubSystem<RenderSubSystem>())
        {
            RendererObject = RSubSystem->GetRenderer();
        }

        if (!m_Implementation || !RendererObject)
        {
            return;
        }
        unsigned long long TimeSinceLastUpdate = 0;
        unsigned long long TimeStamp = Timer::GetTimestempForFps(60);
        while (!m_Implementation->m_Exit)
        {
            auto CurrentTime = m_Implementation->m_Timer.Reset();
            TimeSinceLastUpdate += CurrentTime;

            decltype(auto) DeltaTime = static_cast<float>(TimeSinceLastUpdate) / static_cast<float>(Timer::GetTicksPerSecond());
            GameEngine::GetInstance().UpdateSubSystems(DeltaTime);
            GameWorld->Update(DeltaTime);

            Timer SubStepingTimer;
            while (TimeSinceLastUpdate >= (2 * TimeStamp))
            {
                unsigned long long SubStepingTimeSinceLastUpdate = SubStepingTimer.Reset();
                decltype(auto) SubStepingDeltaTime = static_cast<float>(SubStepingTimeSinceLastUpdate) / static_cast<float>(Timer::GetTicksPerSecond());
                GameEngine::GetInstance().UpdateSubSystems(SubStepingDeltaTime);
                GameWorld->Update(DeltaTime);
                TimeSinceLastUpdate -= TimeStamp;
            } 

            float Interpolation = 0.2; //TODO
            RendererObject->Draw(Interpolation);
        }
    }

    void GameLoop::Deinitialize()
    {
        if (InputSubSystem::Ptr InpSubSystem = GameEngine::GetInstance().GetSubSystem<InputSubSystem>())
        {
            if(InputManager::Ptr InpManager = InpSubSystem->GetManager())
            {
                InpManager->Unregister(m_Implementation);
            }
        }
    }
}