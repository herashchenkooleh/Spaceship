#include "ssg/CollisionSubSystem.hpp"

namespace ssg
{
    CollisionSubSystem::CollisionSubSystem()
    {

    }

    /*virtual*/ CollisionSubSystem::~CollisionSubSystem() = default;

    /*virtual*/ bool CollisionSubSystem::Initialize() /*override*/
    {
        return true;
    }

    /*virtual*/ void CollisionSubSystem::Update(const float InDeltaTime) /*override*/
    {

    }

    /*virtual*/ void CollisionSubSystem::Deinitialize() /*override*/
    {

    }

    /*virtual*/ void CollisionSubSystem::RegisterGameObject(GameObject::Ptr InObject) /*override*/
    {

    }

    /*virtual*/ void CollisionSubSystem::UnregisterGameObject(GameObject::Ptr InObject) /*override*/
    {

    }
}