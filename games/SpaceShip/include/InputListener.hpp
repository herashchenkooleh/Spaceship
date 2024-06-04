#pragma once

#include "Configs.hpp"
#include "InputEvent.hpp"

namespace SpaceShipGame
{
    class InputListener
    {
    public:
        using Ptr = SharedPtr<InputListener>;
        using UUID = unsigned int;

        InputListener();
        virtual ~InputListener();

        UUID GetID() const { return m_ID; }

        virtual void HandleInput(const InputEvent& InEvent);

    private:
        UUID m_ID;
    };
}