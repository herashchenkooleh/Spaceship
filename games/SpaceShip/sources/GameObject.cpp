#include "GameObject.hpp"

namespace SpaceShipGame
{
    GameObject::GameObject() = default;

    /*virtual*/ GameObject::~GameObject() = default;

    /*virtual*/ void GameObject::Update()
    {

    }

    /*virtual*/ bool GameObject::Construct()
    {
        m_IsValid = true;
        return true;
    }

    /*virtual*/ bool GameObject::Destroy()
    {
        return true;
    }
}