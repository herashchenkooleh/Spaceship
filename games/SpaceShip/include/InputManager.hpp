#pragma once


#include "Configs.hpp"
#include "InputEvent.hpp"
#include "GameWindow.hpp"

namespace SpaceShipGame
{
    class InputManager
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<InputManager>;
        using Listener = Function<void(const InputEvent&)>;

    public:
        InputManager();
        ~InputManager();

        bool Initialize(GameWindow::Ptr InGameWindow);
        void Update();

        void Register(InputEvent::Type InType, Listener InFunction);

    private:
        ImplementationPtr m_Implementation;
    };
}
