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

        void AddComponent(GameObjectComponent::Ptr InComponent);
        void RemoveComponent(GameObjectComponent::Ptr InComponent);

        void MarkForDelete() { m_IsValid = false; };
        bool IsMarkForDelete() const { return !m_IsValid; };

    private:
        bool m_IsValid;
        Vector<GameObjectComponent::Ptr> m_Components;
    };
}
