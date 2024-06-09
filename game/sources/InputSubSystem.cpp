#include "ssg/InputSubSystem.hpp"
#include "ssg/InputListenerComponent.hpp"

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

    /*virtual*/ void InputSubSystem::RegisterGameObject(GameObject::Ptr InObject) /*override*/
    {
        if (InputListenerComponent::Ptr InpListener = InObject->GetComponent<InputListenerComponent>())
        {
            m_Manager->Register(InpListener);
        }
    }

    /*virtual*/ void InputSubSystem::UnregisterGameObject(GameObject::Ptr InObject) /*override*/
    {
        if (InputListenerComponent::Ptr InpListener = InObject->GetComponent<InputListenerComponent>())
        {
            m_Manager->Unregister(InpListener);
        }
    }
}