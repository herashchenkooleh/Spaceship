#include "ssg/GameObject.hpp"
#include "ssg/World.hpp"

namespace ssg
{
    GameObject::GameObject()
    {
    }

    /*virtual*/ GameObject::~GameObject()
    {
        if (m_IsValid)
        {
            World::GetCurrentWorld()->UnregisterGameObject(SharedFromThis(this));
            Destroy();
        }
    }

    /*virtual*/ void GameObject::Update(const float InDeltaTime)
    {
        for (auto [Type, Component]: m_Components)
        {
            if (Component)
            {
                Component->Update(InDeltaTime);
            }
        }
    }

    void GameObject::MarkForDelete()
    {
        World::GetCurrentWorld()->UnregisterGameObject(SharedFromThis(this));
        m_IsValid = false;
    };

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