#pragma once

#include "Configs.hpp"
#include "GameStateManager.hpp"
#include "InputManager.hpp"
#include "GameObject.hpp"

namespace SpaceShipGame
{
    class World
    {
    public:
        using Ptr = SharedPtr<World>;

        World();
        World(const World&) = delete;
        World& operator=(const World& InObj) = delete;

        ~World();

        bool Initialize(InputManager::Ptr InInputManager);
        void Update();

    private:
        GameStateManager::Ptr m_StateManager;
        InputManager::Ptr m_InputManager;

        Vector<GameObject::Ptr> m_GameObjects;
    };
}