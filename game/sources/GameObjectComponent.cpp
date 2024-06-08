#include "ssg/GameObjectComponent.hpp"

namespace ssg
{
    GameObjectComponent::GameObjectComponent() = default;

    /*virtual*/ GameObjectComponent::~GameObjectComponent() = default;

    /*virtual*/ void GameObjectComponent::Update(const float InDeltaTime)
    {
        for(auto& [TypeID, ChildComponent]: m_Components)
        {
            if (ChildComponent.first)
            {
                ChildComponent.second->Update(InDeltaTime);
            }
        }
    }

    /*virtual*/ bool GameObjectComponent::Construct()
    {
        for(auto& [TypeID, ChildComponent]: m_Components)
        {
            if (ChildComponent.first)
            {
                ChildComponent.second->Construct();
            }
        }

        return true;
    }

    /*virtual*/ bool GameObjectComponent::Destroy()
    {
        for(auto& [TypeID, ChildComponent]: m_Components)
        {
            if (ChildComponent.first)
            {
                ChildComponent.second->Destroy();
            }
        }

        return true;
    }
}