#pragma once

#include "ssg/Global.hpp"
#include "ssg/Object.hpp"
#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    class GameObject : public Object, public EnableSharedFromThis<GameObject>
    {
    public:
        using Ptr = SharedPtr<GameObject>;

        GameObject();
        virtual ~GameObject();

        virtual void Update(const float InDeltaTime);

        virtual bool Construct();
        virtual bool Destroy();

        template<typename ComponentType, typename ...Args>
        decltype(auto) AddComponent(Args... InArgs)
        {
            if (auto Iter = m_Components.find(TypeIndex(typeid(ComponentType))); Iter != m_Components.end())
            {
                return DynamicPointerCast<ComponentType>(Iter->second);
            }

            auto Component = MakeShared<ComponentType>(std::forward<Args>(InArgs)...);
            m_Components[TypeIndex(typeid(ComponentType))] = Component;

            return DynamicPointerCast<ComponentType>(m_Components[TypeIndex(typeid(ComponentType))]);
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
                return DynamicPointerCast<ComponentType>(Iter->second);
            }
            
            return DynamicPointerCast<ComponentType>(GameObjectComponent::Ptr{ });
        }

        void MarkForDelete();
        bool IsMarkForDelete() const { return !m_IsValid; };

    protected:
        bool m_IsValid;
        UnorderedMap<TypeIndex, GameObjectComponent::Ptr> m_Components;
    };
}
