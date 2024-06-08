#include "ssg/InputEvent.hpp"

namespace ssg
{
    InputEvent::InputEvent()
        : m_Type(Type::Unkwnown)
        , m_KeyIdentifier(Key::Unknown)
    {

    }
    
    InputEvent::~InputEvent() = default;
}