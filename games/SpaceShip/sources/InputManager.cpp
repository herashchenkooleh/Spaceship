#include "InputManager.hpp"

namespace SpaceShipGame
{
    struct InputManager::Implementation
    {

    };

    InputManager::InputManager()
        : m_Implementation(nullptr)
    {

    }
        
    InputManager::~InputManager() = default;

    bool InputManager::Initialize()
    {
        if (m_Implementation)
        {
            return true;
        }

        try
        {
            m_Implementation = MakeShared<Implementation>();
        }
        catch(...)
        {
            return false;
        }
        
        return true;
    }

    void InputManager::HandleEvent(const InputEvent& InEvent)
    {

    }
}