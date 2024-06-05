#pragma once

#include "Configs.hpp"
#include "GameStateManager.hpp"
#include "InputManager.hpp"
#include "GameObject.hpp"
#include "Renderer.hpp"

namespace SpaceShipGame
{
    class World
    {
    public:
        using Ptr = SharedPtr<World>;

        static void SetCurrentWorld(World::Ptr InCurrentWorld);
        static World::Ptr GetCurrentWorld();

        World();
        World(const World&) = delete;
        World& operator=(const World& InObj) = delete;

        ~World();

        bool Initialize(InputManager::Ptr InInputManager, Renderer::Ptr InRenderer);
        void Update(const float InDeltaTime);

        void RegisterGameObject(GameObject::Ptr InGameObject);

    private:
        GameStateManager::Ptr m_StateManager;
        InputManager::Ptr m_InputManager;
        Renderer::Ptr m_Renderer;

        Mutex m_NewPlacedGameObjectsMutex;
        Vector<GameObject::Ptr> m_NewPlacedGameObjects;

        Vector<GameObject::Ptr> m_GameObjects;

        static World::Ptr s_CurrentWorld;
        static Mutex s_CurrentWorldMutex;

    };
}