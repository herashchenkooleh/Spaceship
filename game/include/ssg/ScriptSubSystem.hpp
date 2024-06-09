#pragma once

#include "ssg/ISubSystem.hpp"
#include "ssg/ScriptManager.hpp"

namespace ssg
{
    class ScriptSubSystem : public ISubSystem
    {
    public:
        using Ptr = SharedPtr<ScriptSubSystem>;

        ScriptSubSystem();
        virtual ~ScriptSubSystem();

        virtual bool Initialize() override;
        virtual void Update(const float InDeltaTime) override;
        virtual void Deinitialize() override;

        ScriptManager::Ptr GetManager() { return m_Manager; }

        virtual void RegisterGameObject(GameObject::Ptr InObject) override;
        virtual void UnregisterGameObject(GameObject::Ptr InObject) override;

    private:
        ScriptManager::Ptr m_Manager;
    };
}