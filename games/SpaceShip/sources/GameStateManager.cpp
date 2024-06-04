#include "GameStateManager.hpp"

namespace SpaceShipGame
{
    GameStateManager::GameStateManager() = default;
    GameStateManager::~GameStateManager() = default;

    void GameStateManager::RegisterState(GameStateBase::Handle InHandler, GameStateBase::Ptr InState)
    {
        if (InState && InState->Initialize())
        {
            m_States[InHandler] = InState;
        }
    }

    void GameStateManager::Activate(GameStateBase::Handle InHandler)
    {
        auto Iter = m_States.find(InHandler);
        if (Iter != m_States.end())
        {
            if (m_ActiveState)
            {
                m_ActiveState->Exit();
            }
            
            m_ActiveState = Iter->second;

            m_ActiveState->Enter();
        }
    }

    void GameStateManager::Update()
    {
        if (m_ActiveState)
        {
            m_ActiveState->Update();
        }
    }

    void GameStateManager::DeactivateCurrent()
    {
        m_ActiveState = nullptr;
    }
}