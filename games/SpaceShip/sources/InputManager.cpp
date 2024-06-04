#include "InputManager.hpp"

namespace SpaceShipGame
{
    struct InputManager::Implementation
    {
        GameWindow::Ptr m_GameWindow;

        MultiMap<InputEvent::Type, InputListener::Ptr> m_Listeners;

        Implementation(GameWindow::Ptr InGameWindow);
        ~Implementation();
    };

    InputManager::Implementation::Implementation(GameWindow::Ptr InGameWindow)
        : m_GameWindow(InGameWindow)
    {

    }

    InputManager::Implementation::~Implementation() = default;

    InputManager::InputManager()
        : m_Implementation(nullptr)
    {

    }
        
    InputManager::~InputManager() = default;

    bool InputManager::Initialize(GameWindow::Ptr InGameWindow)
    {
        if (m_Implementation)
        {
            return true;
        }

        try
        {
            m_Implementation = MakeShared<Implementation>(InGameWindow);
        }
        catch(...)
        {
            return false;
        }
        
        return true;
    }

    void InputManager::Update()
    {
        InputEvent Event = m_Implementation->m_GameWindow->PollEvent();
        auto Listeners = m_Implementation->m_Listeners.equal_range(Event.GetType());
 
        for (auto Iter = Listeners.first; Iter != Listeners.second; ++Iter)
        {
            Iter->second->HandleInput(Event);
        }
    }

    void InputManager::Register(InputEvent::Type InType, InputListener::Ptr InListener)
    {
        m_Implementation->m_Listeners.insert({ InType, InListener });
    }
}