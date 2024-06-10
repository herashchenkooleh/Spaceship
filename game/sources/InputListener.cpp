#include "ssg/InputListener.hpp"

namespace ssg
{    
    InputListener::InputListener() = default;
    
    /*virtual*/ InputListener::~InputListener() = default;   

    /*virtual*/ void InputListener::HandleInput(const InputEvent& InEvent)
    {

    }
}
