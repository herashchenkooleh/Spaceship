#pragma once

#include "ssg/GameStateBase.hpp"
#include "ssg/Pawn.hpp"

namespace ssg
{
    class ShellGameState : public GameStateBase, public EnableSharedFromThis<ShellGameState>
    {
        friend class ShellGameStateScript;
    public:
        using Ptr = SharedPtr<ShellGameState>;

        ShellGameState();
        ~ShellGameState();

        virtual bool Initialize() override;
        virtual bool Enter() override;
        virtual void Update() override;
        virtual void Exit() override;

        virtual void HandleInput(const InputEvent& InEvent) override;
        virtual GameStateBase::Handle GetHandle() const override;

        static Handle s_ShellHandle;

        static bool RegisterScriptType();
    };
}