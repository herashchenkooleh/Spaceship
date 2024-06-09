#include "ssg/InputListener.hpp"

namespace ssg
{    
    InputListener::InputListener(const Vector<InputEvent::Type>& InEventTypes)
        : m_EventTypes(InEventTypes)
    {

    }
    /*virtual*/ InputListener::~InputListener() = default;   

    /*virtual*/ void InputListener::HandleInput(const InputEvent& InEvent)
    {

    }
}
