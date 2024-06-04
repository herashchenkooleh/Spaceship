#include "World.hpp"

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
            //TODO create all needed game state and register in manager

            m_StateManager = MakeShared<GameStateManager>();
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
    }

}