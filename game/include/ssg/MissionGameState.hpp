#pragma once

#include "ssg/GameStateBase.hpp"
#include "ssg/Objective.hpp"

namespace ssg
{
    class MissionGameState : public GameStateBase, public EnableSharedFromThis<MissionGameState>
    {
        friend class MissionGameStateScript;
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

        static bool RegisterScriptType();

    private:
        int m_NumberObjectives;
        String m_PlayerControllerScript;
        Vector<Objective> m_Objectives;
    };
}