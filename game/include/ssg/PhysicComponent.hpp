#pragma once

#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class PhysicComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<PhysicComponent>;

        PhysicComponent();
        ~PhysicComponent();
    };
}