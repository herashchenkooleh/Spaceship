#pragma once

#include "GameObject.hpp"

namespace SpaceShipGame
{
    class Actor : public GameObject
    {
    public:
        virtual bool Construct() override;
    };
}