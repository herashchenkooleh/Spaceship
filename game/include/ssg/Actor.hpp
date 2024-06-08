#pragma once

#include "ssg/GameObject.hpp"

namespace ssg
{
    class Actor : public GameObject
    {
    public:
        virtual bool Construct() override;
    };
}