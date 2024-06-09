#pragma once

#include "ssg/Global.hpp"
#include "ssg/GameStateManager.hpp"
#include "ssg/GameObject.hpp"
#include "ssg/Character.hpp"
#include "ssg/PlayerController.hpp"
#include "ssg/Level.hpp"

namespace ssg
{
    class World
    {
    public:
        using Ptr = SharedPtr<World>;

        static void SetCurrentWorld(World::Ptr InCurrentWorld);
        static World::Ptr GetCurrentWorld();

        World();
        World(const World &) = delete;
        World &operator=(const World &InObj) = delete;

        ~World();

        bool Initialize();
        void Update(const float InDeltaTime);

        void RegisterGameObject(GameObject::Ptr InGameObject);
        void UnregisterGameObject(GameObject::Ptr InGameObject);

        bool LoadLevel(const String& InFilePath);
        void UnloadLevel();

        void OnGameStateExit();
        void OnGameStateEnter();

    private:
        GameStateManager::Ptr m_StateManager;

        Mutex m_NewPlacedGameObjectsMutex;
        Vector<GameObject::Ptr> m_NewPlacedGameObjects;

        Mutex m_MarketDeleteGameObjectsMutex;
        Vector<GameObject::Ptr> m_MarketDeleteGameObjects;

        static World::Ptr s_CurrentWorld;
        static Mutex s_CurrentWorldMutex;

        PlayerController::Ptr m_PlayerController;

        Level::Ptr m_Level;
    };
}