#include "ssg/GameObject.hpp"
#include "ssg/GameEngine.hpp"

namespace ssg
{
    GameObject::GameObject()
    {
        GameEngine::GetInstance().RegisterGameObject(SharedFromThis(this));
    }

    /*virtual*/ GameObject::~GameObject()
    {
        if (m_IsValid)
        {
            GameEngine::GetInstance().UnregisterGameObject(SharedFromThis(this));
        }
    }

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