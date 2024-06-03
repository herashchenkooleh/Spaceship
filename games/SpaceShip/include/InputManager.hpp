#pragma once


#include "Configs.hpp"
#include "InputEvent.hpp"

namespace SpaceShipGame
{
    class InputManager
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<InputManager>;

    public:
        InputManager();
        ~InputManager();

        bool Initialize();

        void HandleEvent(const InputEvent& InEvent);

    private:
        ImplementationPtr m_Implementation;
    };
}
