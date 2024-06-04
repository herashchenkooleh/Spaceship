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

        virtual void Update();

        void AddComponent(GameObjectComponent::Ptr InComponent, const bool InNeedUpdate = false);
        void RemoveComponent(GameObjectComponent::Ptr InComponent);

    private:
        using ChildComponent = Pair<bool, GameObjectComponent::Ptr>;

        Vector<ChildComponent> m_ChildComponents;
    };
}