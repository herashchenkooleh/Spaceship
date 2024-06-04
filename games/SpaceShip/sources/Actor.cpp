#include "Actor.hpp"

#include "PositionComponent.hpp"

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