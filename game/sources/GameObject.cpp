#include "ssg/GameObject.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp" 
#include "ssg/World.hpp"
#include "ssg/WeaponComponent.hpp"

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
                                                         "Update", &GameObject::m_UpdateFunction);
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

                    m_IsValid = true;
                }
            }
        }
    }

    /*virtual*/ GameObject::~GameObject()
    {
        if (m_IsValid)
        {
            World::GetCurrentWorld()->UnregisterGameObject(SharedFromThis(this));
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
}