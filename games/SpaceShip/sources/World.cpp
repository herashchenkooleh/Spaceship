#include "World.hpp"
#include "MissionGameState.hpp"
#include "ShellGameState.hpp"
#include "MeshComponent.hpp"
#include <iostream>

namespace SpaceShipGame
{
    /*static*/ World::Ptr World::s_CurrentWorld = nullptr;
    /*static*/ Mutex World::s_CurrentWorldMutex;

    /*static*/ void World::SetCurrentWorld(World::Ptr InCurrentWorld)
    {
        Lock<Mutex> Lock(s_CurrentWorldMutex);
        s_CurrentWorld = InCurrentWorld;
    }

    /*static*/ World::Ptr World::GetCurrentWorld()
    {
        Lock<Mutex> Lock(s_CurrentWorldMutex);
        return s_CurrentWorld;
    }

    World::World()
        : m_StateManager(nullptr)
        , m_InputManager(nullptr)
    {

    }

    World::~World() = default;

    bool World::Initialize(InputManager::Ptr InInputManager, Renderer::Ptr InRenderer)
    {
        if (!InInputManager || !InRenderer)
        {
            return false;
        }

        m_InputManager = InInputManager;
        m_Renderer = InRenderer;

        try
        {
            GameStateBase::Ptr MGameState = MakeShared<MissionGameState>();
            GameStateBase::Ptr SGameState = MakeShared<ShellGameState>();

            m_StateManager = MakeShared<GameStateManager>();

            m_StateManager->RegisterState(MissionGameState::s_MissionHandle, MGameState);
            m_StateManager->RegisterState(ShellGameState::s_ShellHandle, SGameState);

            m_StateManager->Activate(MissionGameState::s_MissionHandle);

            //m_InputManager->Register(SGameState);
            //m_InputManager->Register(MGameState);
        }
        catch(...)
        {
            return false;
        }
        
        return true;
    }

    void World::Update(const float InDeltaTime)
    {
        if (!m_StateManager || !m_InputManager)
        {
            return;
        }

        {
            Lock<Mutex> Lock(m_NewPlacedGameObjectsMutex);
            for (auto Object: m_NewPlacedGameObjects)
            {
                if (!Object)
                {
                    continue;
                }
                Object->Construct();
                MeshComponent::Ptr Mesh = Object->GetComponent<MeshComponent>();
                if (Mesh)
                {
                    m_Renderer->Register(Mesh);
                }
                m_GameObjects.push_back(Object);
            }
            m_NewPlacedGameObjects.clear();
        }
        m_StateManager->Update();

        for (auto Object: m_GameObjects)
        {
            if (Object)
            {
                Object->Update(InDeltaTime);
            }
        }

        for (auto Object: m_GameObjects)
        {
            if (Object->IsMarkForDelete())
            {
                MeshComponent::Ptr Mesh = Object->GetComponent<MeshComponent>();
                if (Mesh)
                {
                    m_Renderer->Unregister(Mesh);
                }
                Object->Destroy();
            }
        }

        auto DeletePredicate = [&](const GameObject::Ptr InObj) 
        {
            return InObj->IsMarkForDelete();
        };

        RemoveIf(m_GameObjects.begin(), m_GameObjects.end(), DeletePredicate);
    }

    void World::RegisterGameObject(GameObject::Ptr InGameObject)
    {
        Lock<Mutex> Lock(m_NewPlacedGameObjectsMutex);
        m_NewPlacedGameObjects.push_back(InGameObject);
    }
}