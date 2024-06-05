#pragma once


#include "Configs.hpp"
#include "InputListener.hpp"
#include "GameWindow.hpp"

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

        bool Initialize(GameWindow::Ptr InGameWindow);
        void Update();

        void Register(InputListener::Ptr InListener, InputEvent::Type InType = InputEvent::Type::All);
        void Unregister(InputListener::Ptr InListener);

    private:
        ImplementationPtr m_Implementation;
    };
}
