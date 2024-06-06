#include "InputEvent.hpp"

namespace SpaceShipGame
{
    InputEvent::InputEvent()
        : m_Type(Type::Unkwnown)
        , m_KeyIdentifier(Key::Unknown)
    {

    }
    
    InputEvent::~InputEvent() = default;
}