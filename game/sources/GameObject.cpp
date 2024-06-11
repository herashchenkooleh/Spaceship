#include "ssg/GameObject.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp" 
#include "ssg/World.hpp"

namespace ssg
{
    /*static*/ bool GameObject::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<GameObject>("GameObject", sol::base_classes, sol::bases<Object>(),
                                                         "Update", &GameObject::m_UpdateFunction,
                                                         "COnstruct", &GameObject::m_ConstructFunction,
                                                         "Destroy", &GameObject::m_DestroyFunction);
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

    GameObject::GameObject()
    {
        if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
        {
            if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
            {
                if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                {
                    m_UpdateFunction = sol::make_reference<sol::function>(SState->lua_state(), &GameObject::DefaultScriptUpdate);
                    m_ConstructFunction = sol::make_reference<sol::function>(SState->lua_state(), &GameObject::DefaultScriptConstruct);
                    m_DestroyFunction = sol::make_reference<sol::function>(SState->lua_state(), &GameObject::DefaultScriptDestroy);
                }
            }
        }
    }

    /*virtual*/ GameObject::~GameObject()
    {
        if (m_IsValid)
        {
            World::GetCurrentWorld()->UnregisterGameObject(SharedFromThis(this));
            Destroy();
        }
    }

    /*virtual*/ void GameObject::Update(const float InDeltaTime)
    {
        decltype(auto) Status = m_UpdateFunction.call(InDeltaTime);
        if (!Status.valid())
        {
            DefaultScriptUpdate(InDeltaTime);
        }
    }

    void GameObject::MarkForDelete()
    {
        World::GetCurrentWorld()->UnregisterGameObject(SharedFromThis(this));
        m_IsValid = false;
    };

    /*virtual*/ bool GameObject::Construct()
    {
        m_IsValid = true;

        return true;
    }

    /*virtual*/ bool GameObject::Destroy()
    {
        for (auto& [TypeID, ChildComponent]: m_Components)
        {
            if (ChildComponent)
            {
                ChildComponent->Destroy();
            }
        }

        return true;
    }

    void GameObject::DefaultScriptUpdate(const float InDeltaTime)
    {
        for (auto [Type, Component]: m_Components)
        {
            if (Component)
            {
                Component->Update(InDeltaTime);
            }
        }
    }

    bool GameObject::DefaultScriptConstruct()
    {
        return this->Construct();
    }

    bool GameObject::DefaultScriptDestroy()
    {
        return this->Destroy();
    }
}