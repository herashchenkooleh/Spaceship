#include "ssg/PositionComponent.hpp"

namespace ssg
{
    PositionComponent::PositionComponent()
        : m_Position({ 0.0f, 0.0f })
    {

    }

    /*virtual*/ PositionComponent::~PositionComponent()  = default;
}