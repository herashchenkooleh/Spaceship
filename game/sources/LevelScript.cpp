#include "ssg/LevelScript.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "ssg/World.hpp"
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
                    m_Level->m_Background = SState->get_or<Pawn::Ptr>("background", nullptr);
                    m_Level->m_Foreground = SState->get_or<Pawn::Ptr>("foreground", nullptr);
                    m_Level->m_Character = SState->get_or<Pawn::Ptr>("character", nullptr);
                    m_Level->m_Spawner = SState->get<AsteroidSpawner::Ptr>("asteroid_spawner");
                    std::cout << "Spawner: " << (m_Level->m_Spawner ? m_Level->m_Spawner->GetID() :  -1) << std::endl;
                    //World::GetCurrentWorld()->RegisterGameObject(m_Level->m_Spawner);

                    return true;
                }
            }
        }

        return false;
    }
}