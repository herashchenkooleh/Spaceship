#include "GameObject.hpp"

namespace SpaceShipGame
{
    GameObject::GameObject() = default;

    /*virtual*/ GameObject::~GameObject() = default;

    /*virtual*/ void GameObject::Update(const float InDeltaTime)
    {
        for (auto& [TypeID, ChildComponent]: m_Components)
        {
            if (ChildComponent)
            {
                ChildComponent->Update(InDeltaTime);
            }
        }
    }

    /*virtual*/ bool GameObject::Construct()
    {
        m_IsValid = true;

        return true;
    }

    /*virtual*/ bool GameObject::Destroy()
    {
        for (auto& [TypeID, ChildComponent]: m_Components)
        {
            if (ChildComponent)
            {
                ChildComponent->Destroy();
            }
        }

        return true;
    }
}