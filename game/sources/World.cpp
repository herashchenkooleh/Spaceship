#include "ssg/World.hpp"
#include "ssg/MissionGameState.hpp"
#include "ssg/ShellGameState.hpp"
#include "ssg/MeshComponent.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/InputSubSystem.hpp"
#include "ssg/Configs.hpp"
#include "ssg/FileSystemHelper.hpp"

#include "ssg/SpawnGameObject.hpp"

namespace ssg
{
    /*static*/ World::Ptr World::s_CurrentWorld = nullptr;
    /*static*/ Mutex World::s_CurrentWorldMutex;

    /*static*/ void World::SetCurrentWorld(World::Ptr InCurrentWorld)
    {
        Lock<Mutex> Lock(s_CurrentWorldMutex);
        s_CurrentWorld = InCurrentWorld;
    }

    /*static*/ World::Ptr World::GetCurrentWorld()
    {
        Lock<Mutex> Lock(s_CurrentWorldMutex);
        return s_CurrentWorld;
    }

    World::World()
        : m_StateManager(nullptr)
        , m_Level(nullptr)
    {

    }

    World::~World() = default;

    bool World::Initialize()
    {
        try
        {
            decltype(auto) MissionScriptPath = FileSystemHelper::GetAssetFilePath(Configs::GetInstance().GetSetting<ssg::String>(ssg::Configs::s_GlobalDefaultMissionGameStateSettingName));
            decltype(auto) ShellScriptPath = FileSystemHelper::GetAssetFilePath(Configs::GetInstance().GetSetting<ssg::String>(ssg::Configs::s_GlobalDefaultShellGameStateSettingName));

            GameStateBase::Ptr MGameState = MakeShared<MissionGameState>();
            GameStateBase::Ptr SGameState = MakeShared<ShellGameState>();

            MGameState->SetScriptFilePath(MissionScriptPath);
            SGameState->SetScriptFilePath(ShellScriptPath);

            m_StateManager = MakeShared<GameStateManager>();

            m_StateManager->RegisterState(MissionGameState::s_MissionHandle, MGameState);
            m_StateManager->RegisterState(ShellGameState::s_ShellHandle, SGameState);

            m_StateManager->SetOnGameStateEnterCallback(Bind(&World::OnGameStateEnter, this));
            m_StateManager->SetOnGameStateExitCallback(Bind(&World::OnGameStateExit, this));

            m_StateManager->Activate(MissionGameState::s_MissionHandle);
            m_PlayerController = MakeShared<PlayerController>();
            GameEngine::GetInstance().RegisterGameObject(m_PlayerController);

            m_Level = MakeShared<Level>();
        }
        catch(std::exception& e)
        {
            return false;
        }
        
        return true;
    }

    void World::Update(const float InDeltaTime)
    {
        if (!m_StateManager)
        {
            return;
        }

        m_StateManager->Update();
        m_PlayerController->Update(InDeltaTime);
        
        {
            Lock<Mutex> Lock(m_MarketDeleteGameObjectsMutex);
            for (auto Object: m_MarketDeleteGameObjects)
            {
                m_Level->RemoveGameObject(Object);
                GameEngine::GetInstance().UnregisterGameObject(Object);
            }
            m_MarketDeleteGameObjects.clear();
        }

        {
            Lock<Mutex> Lock(m_NewPlacedGameObjectsMutex);
            for (auto Object: m_NewPlacedGameObjects)
            {
                if (!Object)
                {
                    continue;
                }
                GameEngine::GetInstance().RegisterGameObject(Object);
                m_Level->AddGameObject(Object);
            }
            m_NewPlacedGameObjects.clear();
        }

        m_Level->Update(InDeltaTime);
    }

    void World::RegisterGameObject(GameObject::Ptr InGameObject)
    {
        Lock<Mutex> Lock(m_NewPlacedGameObjectsMutex);
        m_NewPlacedGameObjects.push_back(InGameObject);
    }

    void World::UnregisterGameObject(GameObject::Ptr InGameObject)
    {
        Lock<Mutex> Lock(m_MarketDeleteGameObjectsMutex);
        m_MarketDeleteGameObjects.push_back(InGameObject);
    }

    void World::OnGameStateExit()
    {
        m_PlayerController->Deinitialize();
        m_Level->Unload();
    }

    void World::OnGameStateEnter()
    {
        if (GameStateBase::Ptr GameState = m_StateManager->GetActiveState())
        {
            m_Level->Load(FileSystemHelper::GetAssetFilePath(GameState->GetLevelFilePath()));

            decltype(auto) PlayerControllerScript = GameState->GetPlayerControllerFilePath();
            if (!PlayerControllerScript.empty())
            {
                m_PlayerController->Initialize(FileSystemHelper::GetAssetFilePath(PlayerControllerScript), m_Level->GetCharacter());
            }
        }
    }
}