#pragma once

#include "ssg/World.hpp"

namespace ssg
{
    template<typename Type, typename ...Args>
    typename Type::Ptr SpawnGameObject(Args&&... InArgs)
    {
        typename Type::Ptr Object = MakeShared<Type>(std::forward<Args>(InArgs)...);
        World::GetCurrentWorld()->RegisterGameObject(Object);
        return Object;
    }
}
