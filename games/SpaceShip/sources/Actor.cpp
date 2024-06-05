#include "Actor.hpp"
#include "World.hpp"
#include "PositionComponent.hpp"
#include "MeshComponent.hpp"
#include <iostream>

namespace SpaceShipGame
{
    /*virtual*/ bool Actor::Construct() /*override*/
    {
        if (!GameObject::Construct())
        {
            return false;
        }

        AddComponent<PositionComponent>();

        return true;
    }
}