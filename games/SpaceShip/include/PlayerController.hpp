#pragma once

#include "GameObject.hpp"
#include "InputListener.hpp"

namespace SpaceShipGame
{
    class PlayerController : public InputListener
    {
    public:
        using Ptr = SharedPtr<PlayerController>;

        PlayerController();
        ~PlayerController();

        bool Initialize(GameObject::Ptr InObject);

        virtual void HandleInput(const InputEvent& InEvent) override;

    private:
        GameObject::Ptr m_Object;
    };
}