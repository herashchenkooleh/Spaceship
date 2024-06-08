#pragma once

#include "ssg/Global.hpp"
#include "ssg/Object.hpp"

namespace ssg
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

        template<typename ComponentType>
        decltype(auto) AddComponent(typename ComponentType::Ptr InComponent, bool NeedUpdate = false)
        {
            if (auto Iter = m_Components.find(TypeIndex(typeid(ComponentType))); Iter != m_Components.end())
            {
                return DynamicPointerCast<ComponentType>(Iter->second.second);
            }
            m_Components[TypeIndex(typeid(ComponentType))] = {  NeedUpdate, InComponent };
            
            return DynamicPointerCast<ComponentType>(m_Components[TypeIndex(typeid(ComponentType))].second);
        }

        template<typename ComponentType, typename ...Args>
        decltype(auto) AddNewComponent(Args... InArgs)
        {
            if (auto Iter = m_Components.find(TypeIndex(typeid(ComponentType))); Iter != m_Components.end())
            {
                return DynamicPointerCast<ComponentType>(Iter->second.second);
            }

            auto Component = MakeShared<ComponentType>(std::forward<Args>(InArgs)...);
            m_Components[TypeIndex(typeid(*Component.get()))] = {  true, Component };
            
            return DynamicPointerCast<ComponentType>(m_Components[TypeIndex(typeid(ComponentType))].second);
        }

        template<typename ComponentType>
        void RemoveComponent()
        {
            m_Components.erase(TypeIndex(typeid(ComponentType)));
        }

        template<typename ComponentType>
        decltype(auto) GetComponent() const
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