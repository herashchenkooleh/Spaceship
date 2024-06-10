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
                        SState->new_usertype<Level>("Level", "background", &Level::m_BackgroundAsset,
                                                              "character_mesh", &Level::m_CharacterMesh);
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
        if (!Status)
        {
            return false;
        }

        //TODO transform from lua
        m_Background = SpawnGameObject<Pawn>(FileSystemHelper::GetAssetFilePath(m_BackgroundAsset), Transform{{0.5f, 0.6f}, 0.0f, {330.0f , 300.0f}});

        if (!m_CharacterMesh.empty())
        {
           m_Character = SpawnGameObject<Pawn>(FileSystemHelper::GetAssetFilePath(m_CharacterMesh), Transform{{0.07f, 0.07f}, 0.0f, {330.0f , 300.0f}});
        }

        return true;
    }

    void Level::Update(const float InDeltaTime)
    {
        m_Character->Update(InDeltaTime);

        for (auto Object: m_GameObjects)
        {
            Object->Update(InDeltaTime);
        }

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
        m_Background.reset();
        m_BackgroundAsset.clear();
    }
}