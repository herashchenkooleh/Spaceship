#include "GameStateManager.hpp"
#include <iostream>

namespace SpaceShipGame
{
    GameStateManager::GameStateManager()
        : m_ActiveState(nullptr)

    {

    }

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
        m_ActiveStateHandle = InHandler;
    }

    void GameStateManager::Update()
    {
        if (m_ActiveStateHandle == GameStateBase::s_InvalidHandle)
        {
            return;
        }

        if (!m_ActiveState || m_ActiveStateHandle != m_ActiveState->GetHandle())
        {
            auto Iter = m_States.find(m_ActiveStateHandle);
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