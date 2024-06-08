#include "ssg/Actor.hpp"
#include "ssg/World.hpp"
#include "ssg/PositionComponent.hpp"

namespace ssg
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