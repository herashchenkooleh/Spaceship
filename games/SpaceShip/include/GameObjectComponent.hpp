#pragma once

#include "Configs.hpp"
#include "Object.hpp"

namespace SpaceShipGame
{
    class GameObjectComponent : public Object
    {
    public:
        using Ptr = SharedPtr<GameObjectComponent>;

        GameObjectComponent();
        virtual ~GameObjectComponent();

        virtual void Update(const float InDeltaTime);

        virtual bool Construct();
        virtual bool Destroy();

        template<typename ComponentType, typename ...Args>
        decltype(auto) AddComponent(const bool NeedUpdate, Args... InArgs)
        {
            if (auto Iter = m_Components.find(TypeIndex(typeid(ComponentType))); Iter != m_Components.end())
            {
                return DynamicPointerCast<ComponentType>(Iter->second.second);
            }

            auto Component = MakeShared<ComponentType>(std::forward<Args>(InArgs)...);
            m_Components[typeid(*Component.get())] = {  NeedUpdate, Component };
            
            return DynamicPointerCast<ComponentType>(m_Components[typeid(Component.get())].second);
        }

        template<typename ComponentType>
        void RemoveComponent()
        {
            m_Components.erase(TypeIndex(typeid(ComponentType)));
        }

        template<typename ComponentType>
        decltype(auto) GetComponent()
        {
            if (auto Iter = m_Components.find(TypeIndex(typeid(ComponentType))); Iter != m_Components.end())
            {
                return  DynamicPointerCast<ComponentType>(Iter->second.second);
            }
            
            return DynamicPointerCast<ComponentType>(GameObjectComponent::Ptr{ });
        }

    private:
        using ChildComponent = Pair<bool, GameObjectComponent::Ptr>;

        bool m_IsValid;
        UnorderedMap<TypeIndex, ChildComponent> m_Components;
    };
}