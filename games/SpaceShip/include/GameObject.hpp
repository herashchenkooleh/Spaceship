#pragma once

#include "Configs.hpp"
#include "Object.hpp"
#include "GameObjectComponent.hpp"

namespace SpaceShipGame
{
    class GameObject : public Object
    {
    public:
        using Ptr = SharedPtr<GameObject>;

        GameObject();
        virtual ~GameObject();

        virtual void Update();

        virtual bool Construct();
        virtual bool Destroy();

        template<typename ComponentType, typename ...Args>
        decltype(auto) AddComponent(Args... InArgs)
        {
            if (auto Iter = m_Components.find(TypeIndex(typeid(ComponentType))); Iter != m_Components.end())
            {
                return Iter->second;
            }

            auto Component = MakeShared<ComponentType>(std::forward<Args>(InArgs)...);
            m_Components[typeid(Component.get())] = Component;
            
            return Component;
        }

        template<typename ComponentType>
        void RemoveComponent()
        {
            m_Components.erase(TypeIndex(typeid(ComponentType)));
        }

        void MarkForDelete() { m_IsValid = false; };
        bool IsMarkForDelete() const { return !m_IsValid; };

    private:
        bool m_IsValid;
        UnorderedMap<TypeIndex, GameObjectComponent::Ptr> m_Components;
    };
}
