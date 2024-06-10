#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <functional>
#include <algorithm>
#include <typeindex>
#include <array>
#include <mutex>
#include <any>
#include <stack>

#include "sol/sol.hpp"
#include "SFML/Graphics.hpp"

namespace ssg
{
    using Any = std::any;

    template <typename Type>
    decltype(auto) AnyCast(Any InValue)
    {
        return std::any_cast<Type>(std::forward<Any>(InValue));
    }

    template <typename Type>
    decltype(auto) Move(Type&& InObj)
    {
        return std::move(std::forward<Type>(InObj));
    }

    using String = std::string;

    using Mutex = std::mutex;

    template <typename Type>
    using Lock = std::lock_guard<Type>;

    using SizeT = std::size_t;

    template <typename Type, SizeT Dimension>
    using Array = std::array<Type, Dimension>;

    using TypeIndex = std::type_index;

    template <typename FirstType, typename SecondType>
    using Pair = std::pair<FirstType, SecondType>;

    template <typename Iterator, typename Predicate>
    decltype(auto) RemoveIf(Iterator InBegin, Iterator InEnd, Predicate InPredicate)
    {
        return std::remove_if(std::forward<Iterator>(InBegin), std::forward<Iterator>(InEnd), std::forward<Predicate>(InPredicate));
    }

    template <typename Type>
    using Vector = std::vector<Type>;

    template <typename Type>
    using SharedPtr = std::shared_ptr<Type>;

    template <typename KeyType, typename ValueType>
    using MultiMap = std::multimap<KeyType, ValueType>;

    template <typename KeyType, typename ValueType>
    using Map = std::map<KeyType, ValueType>;

    template <typename KeyType, typename ValueType>
    using UnorderedMap = std::unordered_map<KeyType, ValueType>;

    template <typename Type>
    using EnableSharedFromThis = std::enable_shared_from_this<Type>;

    template <typename Type>
    decltype(auto) SharedFromThis(Type *InThis)
    {
        return InThis->shared_from_this();
    }

    template <typename DestType, typename ResType>
    SharedPtr<DestType> DynamicPointerCast(const SharedPtr<ResType> &InPointer) noexcept
    {
        return std::dynamic_pointer_cast<DestType>(std::forward<const SharedPtr<ResType> &>(InPointer));
    }

    using NullPtr = std::nullptr_t;

    template <typename Type>
    using Function = std::function<Type>;

    template <typename FunctionType, typename... Args>
    decltype(auto) Bind(FunctionType &&InFunction, Args &&...InArgs)
    {
        return std::bind(std::forward<FunctionType>(InFunction), std::forward<Args>(InArgs)...);
    }

    template<size_t Index>
    using Placeholder = std::placeholders::__ph<Index>;

    extern Placeholder<1> Placeholder1;

    template <typename Type, typename... Args>
    SharedPtr<Type> MakeShared(Args &&...InArgs)
    {
        return std::make_shared<Type>(std::forward<Args>(InArgs)...);
    }

    template <typename Type>
    using Stack = std::stack<Type>;

    using ScriptFunction = sol::function;
    using ScriptObject = sol::object;
    using ScriptStackObject = sol::stack_object;
    using ScriptNilObjectType = sol::lua_nil_t;

    extern ScriptNilObjectType ScriptNilObject;

    using FloatRect = sf::FloatRect;
}