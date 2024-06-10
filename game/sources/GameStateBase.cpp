#include "ssg/GameStateBase.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"

#include "sol/sol.hpp"

namespace ssg
{
    /*static*/ bool GameStateBase::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<GameStateBase>("GameStateBase", "level", &GameStateBase::m_LevelFilePath);
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

    int GameStateBase::s_InvalidHandle = -1;

    GameStateBase::GameStateBase() = default;

    /*virtual*/ GameStateBase::~GameStateBase() = default;

    /*virtual*/ bool GameStateBase::Initialize()
    {
        return true;
    }

    /*virtual*/ bool GameStateBase::Enter()
    {
        return true;
    }

    /*virtual*/ void GameStateBase::Update()
    {

    }

    /*virtual*/ void GameStateBase::Exit()
    {

    }

    /*virtual*/ GameStateBase::Handle GameStateBase::GetHandle() const
    {
        return s_InvalidHandle;
    }
}
