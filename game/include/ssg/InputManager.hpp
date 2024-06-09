#pragma once


#include "ssg/Global.hpp"
#include "ssg/InputListener.hpp"
#include "ssg/GameWindow.hpp"

namespace ssg
{
    class InputManager
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<InputManager>;

    public:
        InputManager(GameWindow::Ptr InGameWindow);
        ~InputManager();

        bool Initialize();
        void Update();

        void Register(InputListener::Ptr InListener);
        void Unregister(InputListener::Ptr InListener);

    private:
        ImplementationPtr m_Implementation;
    };
}
