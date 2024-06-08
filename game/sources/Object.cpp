#include "ssg/Object.hpp"

namespace ssg
{
    Object::Identifier Object::s_Counter = 0;

    Object::Object()
        : m_ID(s_Counter++)
    {

    }

    /*virtual*/ Object::~Object() = default;
}