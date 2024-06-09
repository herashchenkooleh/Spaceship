#include "ssg/World.hpp"
#include "ssg/MissionGameState.hpp"
#include "ssg/ShellGameState.hpp"
#include "ssg/MeshComponent.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/InputSubSystem.hpp"

namespace ssg
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
        , m_CurrentLevel(nullptr)
    {

    }

    World::~World() = default;

    bool World::Initialize()
    {
        try
        {
            GameStateBase::Ptr MGameState = MakeShared<MissionGameState>();
            GameStateBase::Ptr SGameState = MakeShared<ShellGameState>();

            m_StateManager = MakeShared<GameStateManager>();

            m_StateManager->RegisterState(MissionGameState::s_MissionHandle, MGameState);
            m_StateManager->RegisterState(ShellGameState::s_ShellHandle, SGameState);

            m_StateManager->Activate(ShellGameState::s_ShellHandle);

            m_PlayerController = MakeShared<PlayerController>();
        }
        catch(...)
        {
            return false;
        }
        
        return true;
    }

    void World::Update(const float InDeltaTime)
    {
        if (!m_StateManager)
        {
            return;
        }

        m_StateManager->Update();
        {
            Lock<Mutex> Lock(m_NewPlacedGameObjectsMutex);
            for (auto Object: m_NewPlacedGameObjects)
            {
                if (!Object)
                {
                    continue;
                }
                Object->Construct();
                GameEngine::GetInstance().RegisterGameObject(Object);
            }
            m_NewPlacedGameObjects.clear();
        }

        m_CurrentLevel->Update(InDeltaTime);        

        {
            Lock<Mutex> Lock(m_MarketDeleteGameObjectsMutex);
            for (auto Object: m_MarketDeleteGameObjects)
            {
                GameEngine::GetInstance().UnregisterGameObject(Object);
                Object->Destroy();
            }
            m_MarketDeleteGameObjects.clear();
        }
    }

    void World::RegisterGameObject(GameObject::Ptr InGameObject)
    {
        Lock<Mutex> Lock(m_NewPlacedGameObjectsMutex);
        m_NewPlacedGameObjects.push_back(InGameObject);
    }

    void World::UnregisterGameObject(GameObject::Ptr InGameObject)
    {
        Lock<Mutex> Lock(m_MarketDeleteGameObjectsMutex);
        m_MarketDeleteGameObjects.push_back(InGameObject);
    }
}