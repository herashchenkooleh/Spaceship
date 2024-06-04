#pragma once

#include <map>
#include <unordered_map>
#include <memory>
#include <functional>

namespace SpaceShipGame
{
    template<typename Type>
    using SharedPtr = std::shared_ptr<Type>;

    template<typename KeyType, typename ValueType>
    using MultiMap = std::multimap<KeyType, ValueType>;

    template<typename KeyType, typename ValueType>
    using UnorderedMap = std::unordered_map<KeyType, ValueType>;

    template<typename Type>
    using Function = std::function<Type>;

    template<typename FunctionType, typename ...Args>
    decltype(auto) Bind(FunctionType&& InFunction, Args... InArgs)
    {
        return std::bind(std::forward<FunctionType>(InFunction), std::forward<Args>(InArgs)...);
    }

    extern std::placeholders::__ph<1> Placeholder1;

    template<typename Type, typename ...Args>
    SharedPtr<Type> MakeShared(Args&& ...InArgs)
    {
        return std::make_shared<Type>(std::forward<Args>(InArgs)...);
    }
}