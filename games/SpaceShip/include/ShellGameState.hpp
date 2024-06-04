#pragma once

#include "GameStateBase.hpp"

namespace SpaceShipGame
{
    class ShellGameState : public GameStateBase
    {
    public:
        using Ptr = SharedPtr<ShellGameState>;

        ShellGameState();
        ~ShellGameState();

        virtual bool Initialize() override;
        virtual bool Enter() override;
        virtual void Update() override;
        virtual void Exit() override;

        virtual void HandleInput(const InputEvent& InEvent) override;

        static Handle s_ShellHandle;
    };
}