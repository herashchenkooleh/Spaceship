#pragma once

#include "ssg/GameStateBase.hpp"

namespace ssg
{
    class MissionGameState : public GameStateBase, public EnableSharedFromThis<MissionGameState>
    {
        friend class MissionGameStateScriptBuilder;

    public:
        using Ptr = SharedPtr<MissionGameState>;

        MissionGameState(const String& InGameStateFilePath);
        ~MissionGameState();

        virtual bool Initialize() override;
        virtual bool Enter() override;
        virtual void Update() override;
        virtual void Exit() override;

        virtual void HandleInput(const InputEvent& InEvent) override;
        virtual GameStateBase::Handle GetHandle() const override;

        static Handle s_MissionHandle;
    };
}