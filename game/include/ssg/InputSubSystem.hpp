#pragma once

#include "ssg/ISubSystem.hpp"
#include "ssg/InputManager.hpp"

namespace ssg
{
    class InputSubSystem : public ISubSystem
    {
    public:
        using Ptr = SharedPtr<InputSubSystem>;

        InputSubSystem(GameWindow::Ptr InGameWindow);
        virtual ~InputSubSystem();

        virtual bool Initialize() override;
        virtual void Update(const float InDeltaTime) override;
        virtual void Deinitialize() override;

        InputManager::Ptr GetManager() const { return m_Manager; }

    private:
        InputManager::Ptr m_Manager;
    };
}
