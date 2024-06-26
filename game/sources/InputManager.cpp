#include "ssg/InputManager.hpp"

namespace ssg
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

    InputManager::InputManager(GameWindow::Ptr InGameWindow)
        : m_Implementation(MakeShared<Implementation>(InGameWindow))
    {

    }
        
    InputManager::~InputManager() = default;

    bool InputManager::Initialize()
    {
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

        auto FullListeners = m_Implementation->m_Listeners.equal_range(InputEvent::Type::All);
        for (auto Iter = FullListeners.first; Iter != FullListeners.second; ++Iter)
        {
            Iter->second->HandleInput(Event);
        }
    }

    void InputManager::Register(InputListener::Ptr InListener)
    {
        for (auto Type: InListener->GetEventTypes())
        {
            m_Implementation->m_Listeners.insert({ Type, InListener });
        }
    }

    void InputManager::Unregister(InputListener::Ptr InListener)
    {
        // for (auto Type: InListener->GetEventTypes())
        // {
        //     m_Implementation->m_Listeners.er({ Type, InListener });
        // }
    }
}