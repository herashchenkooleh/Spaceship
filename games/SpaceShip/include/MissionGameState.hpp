#pragma once

#include "Character.hpp"
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
        virtual GameStateBase::Handle GetHandle() const override;

        static Handle s_MissionHandle;

    private:
        Character::Ptr m_Character;
    };
}