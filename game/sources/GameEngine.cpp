#include "ssg/GameEngine.hpp"
#include "ssg/InputSubSystem.hpp"
#include "ssg/RenderSubSystem.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "ssg/GameLoop.hpp"

namespace ssg
{
    /*static*/ GameEngine& GameEngine::GetInstance()
    {
       static GameEngine s_Instance;

       return s_Instance;
    }

    GameEngine::GameEngine()
        : m_Window(nullptr)
    {

    }

    GameEngine::~GameEngine() = default;

    bool GameEngine::Initialize(GameWindow::Ptr InWindow)
    {
        if (!InWindow)
        {
            return false;
        }

        m_Window = InWindow;

        //TODO priority?
        RegisterSubSystem<InputSubSystem>(m_Window);
        RegisterSubSystem<ScriptSubSystem>();
        RegisterSubSystem<RenderSubSystem>(m_Window);

        for (auto [SubSystemType, SubSystem]: m_SubSystems)
        {
            if (!SubSystem || !SubSystem->Initialize())
            {
                return false;
            }
        }

        return true;
    }

    void GameEngine::Deinitialize()
    {
        for (auto [SubSystemType, SubSystem]: m_SubSystems)
        {
            if (SubSystem)
            {
                SubSystem->Deinitialize();
            }
        }

        if (m_Window)
        {
            m_Window->Close();
        }
    }

    void GameEngine::UpdateSubSystems(const float InDeltaTime)
    {
        for (auto [SubSystemType, SubSystem]: m_SubSystems)
        {
            if (SubSystem)
            {
                SubSystem->Update(InDeltaTime);
            }
        }
    }

    void GameEngine::RegisterGameObject(GameObject::Ptr InObject)
    {
        for (auto [SubSystemType, SubSystem]: m_SubSystems)
        {
            if (SubSystem)
            {
                SubSystem->RegisterGameObject(InObject);
            }
        }
    }

    void GameEngine::UnregisterGameObject(GameObject::Ptr InObject)
    {
        for (auto [SubSystemType, SubSystem]: m_SubSystems)
        {
            if (SubSystem)
            {
                SubSystem->UnregisterGameObject(InObject);
            }
        }
    }
}