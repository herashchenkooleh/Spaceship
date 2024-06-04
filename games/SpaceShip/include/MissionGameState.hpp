#pragma once

#include "GameStateBase.hpp"

namespace SpaceShipGame
{
    class MissionGameState : public GameStateBase
    {
    public:
        using Ptr = SharedPtr<MissionGameState>;

        MissionGameState();
        ~MissionGameState();

        virtual bool Initialize() override;
        virtual bool Enter() override;
        virtual void Update() override;
        virtual void Exit() override;

        virtual void HandleInput(const InputEvent& InEvent) override;

        static Handle s_MissionHandle;
    };
}