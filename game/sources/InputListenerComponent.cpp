#include "ssg/InputListenerComponent.hpp"

namespace ssg
{
    InputListenerComponent::InputListenerComponent()
        : InputListener({ InputEvent::Type::All })
    {

    }

    InputListenerComponent::InputListenerComponent(const Vector<InputEvent::Type>& InEventTypes)
        : InputListener(InEventTypes)
    {

    }
    /*virtual*/ InputListenerComponent::~InputListenerComponent() = default;

    /*virtual*/ void InputListenerComponent::HandleInput(const InputEvent& InEvent) /*override*/
    {
        if (auto Iter = m_Callbacks.find(InEvent.GetType()); Iter != m_Callbacks.end())
        {
            Iter->second(InEvent);
        }
    }

    void InputListenerComponent::AddCallback(const InputEvent::Type InEventType, EventCallback InCallback)
    {
        m_Callbacks.insert({ InEventType, InCallback });
    }
}