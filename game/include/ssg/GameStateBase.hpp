#pragma once

#include "ssg/Global.hpp"
#include "ssg/InputListener.hpp"
#include "ssg/GameObject.hpp"

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

    private:
        Vector<GameObject::Ptr> m_GameObjects;
    };
}
