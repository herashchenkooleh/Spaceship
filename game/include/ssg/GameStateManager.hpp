#pragma once

#include "ssg/Global.hpp"
#include "ssg/GameStateBase.hpp"

namespace ssg
{
    class GameStateManager
    {
    public:
        using Ptr = SharedPtr<GameStateManager>;
        using StateChangedCallback = Function<void()>;

        GameStateManager();
        ~GameStateManager();

        GameStateManager(const GameStateManager& InObj) = delete;
        GameStateManager& operator=(const GameStateManager& InObj) = delete;

        void RegisterState(GameStateBase::Handle InHandler, GameStateBase::Ptr InState);

        GameStateBase::Ptr GetActiveState() { return m_ActiveState; }

        void Activate(GameStateBase::Handle InHandler);
        void Update();
        void DeactivateCurrent();

        void SetOnGameStateExitCallback(StateChangedCallback InCallback) { m_GameStateExitCallback = InCallback; };
        void SetOnGameStateEnterCallback(StateChangedCallback InCallback) { m_GameStateEnterCallback = InCallback; };

    private:
        UnorderedMap<GameStateBase::Handle, GameStateBase::Ptr> m_States;

        GameStateBase::Handle m_ActiveStateHandle;
        GameStateBase::Ptr m_ActiveState;

        StateChangedCallback m_GameStateExitCallback;
        StateChangedCallback m_GameStateEnterCallback;
    };
}