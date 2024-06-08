#pragma once

#include "ssg/Global.hpp"
#include "ssg/GameStateBase.hpp"

namespace ssg
{
    class GameStateManager
    {
    public:
        using Ptr = SharedPtr<GameStateManager>;

        GameStateManager();
        ~GameStateManager();

        GameStateManager(const GameStateManager& InObj) = delete;
        GameStateManager& operator=(const GameStateManager& InObj) = delete;

        void RegisterState(GameStateBase::Handle InHandler, GameStateBase::Ptr InState);

        void Activate(GameStateBase::Handle InHandler);
        void Update();
        void DeactivateCurrent();

    private:
        UnorderedMap<GameStateBase::Handle, GameStateBase::Ptr> m_States;

        GameStateBase::Handle m_ActiveStateHandle;
        GameStateBase::Ptr m_ActiveState;
    };
}