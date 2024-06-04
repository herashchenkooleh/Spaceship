#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <functional>
#include <algorithm>
#include <typeindex>

namespace SpaceShipGame
{
    using TypeIndex = std::type_index;

    template<typename FirstType, typename SecondType>
    using Pair = std::pair<FirstType, SecondType>;

    template<typename Iterator, typename Predicate>
    decltype(auto) RemoveIf(Iterator InBegin, Iterator InEnd, Predicate InPredicate)
    {
        return std::remove_if(std::forward<Iterator>(InBegin), std::forward<Iterator>(InEnd), std::forward<Predicate>(InPredicate));
    }

    template<typename Type>
    using Vector = std::vector<Type>;

    template<typename Type>
    using SharedPtr = std::shared_ptr<Type>;

    template<typename KeyType, typename ValueType>
    using MultiMap = std::multimap<KeyType, ValueType>;

    template<typename KeyType, typename ValueType>
    using UnorderedMap = std::unordered_map<KeyType, ValueType>;

    template<typename Type>
    using EnableSharedFromThis = std::enable_shared_from_this<Type>;

    template<typename Type>
    decltype(auto) SharedFromThis(Type* InThis)
    {
        return InThis->shared_from_this();
    }

    // template<typename Type>
    // using Function = std::function<Type>;

    // template<typename FunctionType, typename ...Args>
    // decltype(auto) Bind(FunctionType&& InFunction, Args... InArgs)
    // {
    //     return std::bind(std::forward<FunctionType>(InFunction), std::forward<Args>(InArgs)...);
    // }

    // extern std::placeholders::__ph<1> Placeholder1;

    template<typename Type, typename ...Args>
    SharedPtr<Type> MakeShared(Args&& ...InArgs)
    {
        return std::make_shared<Type>(std::forward<Args>(InArgs)...);
    }
}