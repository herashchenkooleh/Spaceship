#pragma once

#include "Configs.hpp"
#include "Object.hpp"
#include "InputEvent.hpp"

namespace SpaceShipGame
{
    class InputListener : public Object
    {
    public:
        using Ptr = SharedPtr<InputListener>;

        InputListener();
        virtual ~InputListener();

        virtual void HandleInput(const InputEvent& InEvent);
    };
}