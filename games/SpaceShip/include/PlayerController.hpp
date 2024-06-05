#pragma once

#include "InputListener.hpp"

namespace SpaceShipGame
{
    class PlayerController : public InputListener
    {
    public:
        using Ptr = SharedPtr<PlayerController>;

        PlayerController();
        ~PlayerController();
    };
}