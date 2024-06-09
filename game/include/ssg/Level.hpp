#pragma once

#include "ssg/Object.hpp"
#include "ssg/GameObject.hpp"
#include "ssg/Character.hpp"
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

        Character::Ptr GetCharacter() { return m_Character; }

    private:
        Character::Ptr m_Character;
        Vector<GameObject::Ptr> m_GameObjects;
    };
}