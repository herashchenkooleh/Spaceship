#include "InputListener.hpp"

namespace SpaceShipGame
{
    static InputListener::UUID s_GlobalUUID = 0;

    InputListener::InputListener()
        : m_ID(s_GlobalUUID++)
    {

    }
    /*virtual*/ InputListener::~InputListener() = default;   

    /*virtual*/ void InputListener::HandleInput(const InputEvent& InEvent)
    {

    }
}
