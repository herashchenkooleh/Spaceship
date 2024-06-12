#include "ssg/Level.hpp"
#include "ssg/LevelScript.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"
#include "ssg/LevelScript.hpp"
#include "ssg/SpawnGameObject.hpp"
#include "ssg/Configs.hpp"
#include "ssg/FileSystemHelper.hpp"

namespace ssg
{
    /*static*/ bool Level::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<Level>("Level");
                    }
                }
            }
        }
        catch(...)
        {
            return false;
        }

        return true;
    }

    Level::Level() = default;
    
    /*virtual*/ Level::~Level() = default;

    bool Level::Load(const String& InLvlScript)
    {
        LevelScript Script = { SharedFromThis(this) };
        bool Status = Script.Execute(InLvlScript);

        return true;
    }

    void Level::Update(const float InDeltaTime)
    {
        if (m_Spawner)
        {
            m_Spawner->Update(InDeltaTime);
        }
        for (auto [Identifier, Object]: m_GameObjects)
        {
            Object->Update(InDeltaTime);
        }
    }

    void Level::Unload()
    {
        for (auto [Identifier, Object]: m_GameObjects)
        {
            Object->MarkForDelete();
        }
        m_GameObjects.clear();
        m_Character.reset();
        m_Background.reset();
        m_Foreground.reset();
        m_Spawner.reset();
    }

    void Level::AddGameObject(GameObject::Ptr InObj)
    {
        m_GameObjects.insert({ InObj->GetID(), InObj });
    }

    void Level::RemoveGameObject(GameObject::Ptr InObj)
    {
        m_GameObjects.erase(InObj->GetID());
    }
}