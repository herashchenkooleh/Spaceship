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

        GameStateBase(const String& InGameStateFilePath, const Vector<InputEvent::Type>& InEventTypes);
        virtual ~GameStateBase();

        virtual bool Initialize();
        virtual bool Enter();
        virtual void Update();
        virtual void Exit();

        virtual Handle GetHandle() const;

        const String& GetLevelFilePath() const { return m_LevelFilePath; }

    protected:
        String m_LevelFilePath;
        String m_GameStateFilePath;
    };
}
