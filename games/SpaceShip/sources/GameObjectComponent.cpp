#include "GameObjectComponent.hpp"

namespace SpaceShipGame
{
    GameObjectComponent::GameObjectComponent() = default;

    /*virtual*/ GameObjectComponent::~GameObjectComponent() = default;

    /*virtual*/ void GameObjectComponent::Update()
    {
        for(auto& Component: m_ChildComponents)
        {
            if (Component.first)
            {
                Component.second->Update();
            }
        }
    }

    void GameObjectComponent::AddComponent(GameObjectComponent::Ptr InComponent, const bool InNeedUpdate /*= false*/)
    {
        m_ChildComponents.push_back({ InNeedUpdate, InComponent });
    }

    void GameObjectComponent::RemoveComponent(GameObjectComponent::Ptr InComponent)
    {
        RemoveIf(m_ChildComponents.begin(), m_ChildComponents.end(), [InComponent](const ChildComponent& InItem) { return *InItem.second == *InComponent; });
    }
}