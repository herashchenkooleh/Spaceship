#pragma once

#include "ssg/GameStateBase.hpp"
#include "ssg/Character.hpp"

namespace ssg
{
    class ShellGameState : public GameStateBase
    {
    public:
        using Ptr = SharedPtr<ShellGameState>;

        ShellGameState(const String& InGameStateFilePath);
        ~ShellGameState();

        virtual bool Initialize() override;
        virtual bool Enter() override;
        virtual void Update() override;
        virtual void Exit() override;

        virtual void HandleInput(const InputEvent& InEvent) override;
        virtual GameStateBase::Handle GetHandle() const override;

        static Handle s_ShellHandle;

    private:
        Character::Ptr m_Background;
    };
}