#include "World.hpp"
#include "MissionGameState.hpp"
#include "ShellGameState.hpp"
#include "MeshComponent.hpp"

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
        , m_Physic(nullptr)
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

            m_Character = MakeShared<Character>("assets/ship.png");
            RegisterGameObject(m_Character);
            m_PlayerController = MakeShared<PlayerController>();
            if (m_PlayerController && m_PlayerController->Initialize(m_Character))
            {
                m_InputManager->Register(m_PlayerController);
            }

            m_Physic = MakeShared<Physic>();
            if(!m_Physic || !m_Physic->Initialize())
            {
                return false;
            }
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
                if (MeshComponent::Ptr Mesh = Object->GetComponent<MeshComponent>();)
                {
                    m_Renderer->Register(Mesh);
                }

                if(PhysicComponent::Ptr PhComponent = Object->GetComponent<PhysicComponent>())
                {
                    m_Physic->Register(PhComponent);
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
                if (MeshComponent::Ptr Mesh = Object->GetComponent<MeshComponent>())
                {
                    m_Renderer->Unregister(Mesh);
                }

                if (PhysicComponent::Ptr PhComponent = Object->GetComponent<PhysicComponent>())
                {
                    m_Physic->Unregister(PhComponent);
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