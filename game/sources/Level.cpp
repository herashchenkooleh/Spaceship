#include "ssg/Level.hpp"
#include "ssg/LevelScriptBuilder.hpp"

namespace ssg
{
    Level::Level()
    {
        m_Character = MakeShared<Character>("assets/ship.png");
    }
    
    /*virtual*/ Level::~Level() = default;

    bool Level::Load(const String& InLvlScript)
    {
        LevelScriptBuilder Builder = { InLvlScript, SharedFromThis(this) };

        return Builder.ExecuteScript();
    }

    void Level::Update(const float InDeltaTime)
    {

    }

    // auto DeletePredicate = [&](const GameObject::Ptr InObj) 
    //     {
    //         return InObj->IsMarkForDelete();
    //     };

    //     RemoveIf(m_GameObjects.begin(), m_GameObjects.end(), DeletePredicate);
}