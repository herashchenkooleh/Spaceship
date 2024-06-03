#pragma once

#include <memory>

namespace SpaceShipGame
{
    template<typename Type>
    using SharedPtr = std::shared_ptr<Type>;

    template<typename Type, typename ...Args>
    SharedPtr<Type> MakeShared(Args&& ...InArgs)
    {
        return std::make_shared<Type>(std::forward<Args>(InArgs)...);
    }
}