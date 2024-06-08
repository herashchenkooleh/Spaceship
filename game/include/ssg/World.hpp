#pragma once

#include "ssg/Global.hpp"
#include "ssg/GameStateManager.hpp"
#include "ssg/InputManager.hpp"
#include "ssg/GameObject.hpp"
#include "ssg/Renderer.hpp"
#include "ssg/Character.hpp"
#include "ssg/PlayerController.hpp"
#include "ssg/Physic.hpp"

namespace ssg
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

        Character::Ptr m_Character;
        PlayerController::Ptr m_PlayerController;

        Physic::Ptr m_Physic;
    };
}