#pragma once

#include "Configs.hpp"
#include "InputListener.hpp"

namespace SpaceShipGame
{
    class GameStateBase : public InputListener
    {
    public:
        using Ptr = SharedPtr<GameStateBase>;
        using Handle = unsigned int;

        GameStateBase();
        virtual ~GameStateBase();

        virtual bool Initialize();
        virtual bool Enter();
        virtual void Update();
        virtual void Exit();
    };
}
