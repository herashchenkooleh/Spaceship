#pragma once

#include "ssg/GameObject.hpp"

namespace ssg
{
    class Actor : public GameObject
    {
    public:
        Actor();
        virtual ~Actor();

        virtual bool Construct() override;
    };
}