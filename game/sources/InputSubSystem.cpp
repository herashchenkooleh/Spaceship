#include "ssg/InputSubSystem.hpp"

namespace ssg
{
    InputSubSystem::InputSubSystem(GameWindow::Ptr InGameWindow)
        : m_Manager(MakeShared<InputManager>(InGameWindow))
    {

    }
        
    /*virtual*/ InputSubSystem::~InputSubSystem() = default;

    /*virtual*/ bool InputSubSystem::Initialize() /*override*/
    {
        if (!m_Manager || !m_Manager->Initialize())
        {
            return false;
        }
        return true;
    }

    /*virtual*/ void InputSubSystem::Update(const float InDeltaTime) /*override*/
    {
        m_Manager->Update();
    }

    /*virtual*/ void InputSubSystem::Deinitialize() /*override*/
    {
        
    }
}