#pragma once

#include "ssg/Object.hpp"
#include "ssg/GameObject.hpp"
#include "ssg/Pawn.hpp"

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

        static bool RegisterScriptType();

    private:
        Pawn::Ptr m_Background;
        String m_BackgroundAsset;
        String m_CharacterMesh;
        Transform m_CharacterTransform;
        Pawn::Ptr m_Character;
        Vector<GameObject::Ptr> m_GameObjects;
    };
}