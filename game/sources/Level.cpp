#include "ssg/Level.hpp"
#include "ssg/LevelScriptBuilder.hpp"

namespace ssg
{
    Level::Level()
    {

    }
    
    /*virtual*/ Level::~Level() = default;

    bool Level::Load(const String& InLvlScript)
    {
        LevelScriptBuilder Builder = { InLvlScript, SharedFromThis(this) };

        bool Status = Builder.ExecuteScript();
        if (!Status)
        {
            return false;
        }

        return true;
    }

    void Level::Update(const float InDeltaTime)
    {

        auto DeletePredicate = [&](const GameObject::Ptr InObj) 
        {
            return InObj->IsMarkForDelete();
        };
        RemoveIf(m_GameObjects.begin(), m_GameObjects.end(), DeletePredicate);
    }

    void Level::Unload()
    {
        for (auto Object: m_GameObjects)
        {
            Object->MarkForDelete();
        }
        m_Character->MarkForDelete();
        m_GameObjects.clear();
        m_Character.reset();
    }
}