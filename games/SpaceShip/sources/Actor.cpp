#include "Actor.hpp"
#include "World.hpp"
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

        World::GetCurrentWorld()->RegisterGameObject(SharedFromThis(this));

        return true;
    }
}