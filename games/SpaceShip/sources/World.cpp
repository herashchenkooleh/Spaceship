#include "World.hpp"
#include "MissionGameState.hpp"
#include "ShellGameState.hpp"

namespace SpaceShipGame
{
    World::World()
        : m_StateManager(nullptr)
        , m_InputManager(nullptr)
    {

    }

    World::~World() = default;

    bool World::Initialize(InputManager::Ptr InInputManager)
    {
        if (!InInputManager)
        {
            return false;
        }

        m_InputManager = InInputManager;

        try
        {
            GameStateBase::Ptr MGameState = MakeShared<MissionGameState>();
            GameStateBase::Ptr SGameState = MakeShared<ShellGameState>();

            m_StateManager = MakeShared<GameStateManager>();

            m_StateManager->RegisterState(MissionGameState::s_MissionHandle, MGameState);
            m_StateManager->RegisterState(ShellGameState::s_ShellHandle, SGameState);

            m_StateManager->Activate(ShellGameState::s_ShellHandle);

            //m_InputManager->Register(SGameState);
            //m_InputManager->Register(MGameState);
        }
        catch(...)
        {
            return false;
        }
        
        return true;
    }

    void World::Update()
    {
        if (!m_StateManager || !m_InputManager)
        {
            return;
        }

        m_StateManager->Update();

        for (auto Object: m_GameObjects)
        {
            Object->Update();
        }

        for (auto Object: m_GameObjects)
        {
            if (Object->IsMarkForDelete())
            {
                Object->Destroy();
            }
        }

        //TODO remove destroed object from world
        //m_GameObjects.erase();
    }

}