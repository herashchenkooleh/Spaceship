#pragma once

#include "ssg/Global.hpp"
#include "ssg/InputListener.hpp"

namespace ssg
{
    class GameStateBase : public InputListener
    {
    public:
        using Ptr = SharedPtr<GameStateBase>;
        using Handle = int;

        static Handle s_InvalidHandle;

        GameStateBase();
        virtual ~GameStateBase();

        virtual bool Initialize();
        virtual bool Enter();
        virtual void Update();
        virtual void Exit();

        virtual Handle GetHandle() const;

        const String& GetLevelFilePath() const { return m_LevelFilePath; }
        const String& GetPlayerControllerFilePath() const { return m_PlayerControllerScript; }

        static bool RegisterScriptType();

        void SetScriptFilePath(const String& InScriptFilePath) { m_ScriptFilePath = InScriptFilePath; }

    protected:
        String m_LevelFilePath;
        String m_ScriptFilePath;
        String m_PlayerControllerScript;
    };
}
