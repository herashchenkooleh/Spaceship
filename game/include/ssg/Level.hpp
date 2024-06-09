#pragma once

#include "ssg/Object.hpp"
#include "ssg/GameObject.hpp"
#include "ssg/Pawn.hpp"
#include "ssg/IScriptBuilder.hpp"

namespace ssg
{
    class Level : public EnableSharedFromThis<Level>
    {
        friend class LevelScriptBuilder;

    public:
        using Ptr = SharedPtr<Level>;

        Level();
        ~Level();

        bool Load(const String& InLvlScript);
        void Update(const float InDeltaTime);
        void Unload();

        Pawn::Ptr GetCharacter() { return m_Character; }

    private:
        Pawn::Ptr m_Character;
        Vector<GameObject::Ptr> m_GameObjects;
    };
}