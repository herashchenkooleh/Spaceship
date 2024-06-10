// #include "ssg/MissionGameStateScript.hpp"
// #include "ssg/GameEngine.hpp"
// #include "ssg/ScriptSubSystem.hpp"

// #include "sol/sol.hpp"

// namespace ssg
// {
//     MissionGameStateScriptBuilder::MissionGameStateScriptBuilder(const String& InMissionPath, MissionGameState::Ptr InMissionState)
//         : m_Script(InMissionPath)
//         , m_Mission(InMissionState)
//     {
//         try
//         {
//             if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
//             {
//                 if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
//                 {
//                     if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
//                     {
//                         SState->new_usertype<MissionGameState>("Mission", "Level", &MissionGameState::m_LevelFilePath);
//                     }
//                 }
//             }
//         }
//         catch(...)
//         {
//             //TODO
//         }
//     }
//     /*virtual*/ MissionGameStateScriptBuilder::~MissionGameStateScriptBuilder() = default;

//     /*virtual*/ bool MissionGameStateScriptBuilder::ExecuteScript() /*override*/
//     {
//         // if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
//         // {
//         //     if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
//         //     {
//         //         if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
//         //         {
//         //             SState->do_file(m_Script);

//         //             m_Mission->m_LevelFilePath = SState->get<MissionGameState>("mission").m_LevelFilePath;
//         //             return true;
//         //         }
//         //     }
//         // }

//         return false;
//     }
// }