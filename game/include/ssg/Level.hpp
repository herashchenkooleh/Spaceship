#pragma once

#include "ssg/Object.hpp"
#include "ssg/GameObject.hpp"
#include "ssg/Pawn.hpp"
#include "ssg/AsteroidSpawner.hpp"

namespace ssg
{
    class Level : public EnableSharedFromThis<Level>
    {
        friend class LevelScript;
    public:
        using Ptr = SharedPtr<Level>;

        Level();
        ~Level();

        bool Load(const String& InLvlScript);
        void Update(const float InDeltaTime);
        void Unload();

        Pawn::Ptr GetCharacter() { return m_Character; }

        void AddGameObject(GameObject::Ptr InObj);
        void RemoveGameObject(GameObject::Ptr InObj);

        static bool RegisterScriptType();

    private:
        Pawn::Ptr m_Background;
        Pawn::Ptr m_Foreground;
        Pawn::Ptr m_Character;
        Map<Object::Identifier, GameObject::Ptr> m_GameObjects;

        AsteroidSpawner::Ptr m_Spawner;
    };
}