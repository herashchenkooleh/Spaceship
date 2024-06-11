#include "ssg/LevelScript.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"

namespace ssg
{
    LevelScript::LevelScript(Level::Ptr InLevel)
        : m_Level(InLevel)
    {
        
    }

    /*virtual*/ LevelScript::~LevelScript() = default;

    /*virtual*/ bool LevelScript::Execute(const String& InFilePath) /*override*/
    {
        if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
        {
            if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
            {
                if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                {
                    SState->do_file(InFilePath);
                    m_Level->m_BackgroundAsset = SState->get<Level>("level").m_BackgroundAsset;
                    m_Level->m_CharacterMesh = SState->get<Level>("level").m_CharacterMesh;
                    m_Level->m_CharacterTransform = SState->get<Level>("level").m_CharacterTransform;
                    return true;
                }
            }
        }

        return false;
    }
}