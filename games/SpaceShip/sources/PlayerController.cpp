#include "PlayerController.hpp"
#include "MoveComponent.hpp"

namespace SpaceShipGame
{


    PlayerController::PlayerController()
        : m_Object(nullptr)
    {

    }
    
    PlayerController::~PlayerController() = default;

    bool PlayerController::Initialize(GameObject::Ptr InObject)
    {
        m_Object = InObject;

        return true;
    }

    /*virtual*/ void PlayerController::HandleInput(const InputEvent& InEvent) /*override*/
    {
        switch (InEvent.GetType())
        {
        case InputEvent::Type::KeyPressed:
        {
            switch (InEvent.GetKey())
            {
            case InputEvent::Key::A:
            {
                if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
                {
                    MComponent->SetXSpeed(-5.0f);
                }
                break;
            }
            case InputEvent::Key::S:
            {
                if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
                {
                    MComponent->SetYSpeed(5.0f);
                }
                break;
            }
            case InputEvent::Key::D:
            {
                if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
                {
                    MComponent->SetXSpeed(5.0f);
                }
                break;
            }
            case InputEvent::Key::W:
            {
                if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
                {
                    MComponent->SetYSpeed(-5.0f);
                }
                break;
            }
            default:
                break;
            }

            break;
        }
        case InputEvent::Type::KeyReleased:
        {
            switch (InEvent.GetKey())
            {
            case InputEvent::Key::A:
            {
                if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
                {
                    MComponent->SetXSpeed(0.0f);
                }
                break;
            }
            case InputEvent::Key::S:
            {
                if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
                {
                    MComponent->SetYSpeed(0.0f);
                }
                break;
            }
            case InputEvent::Key::D:
            {
                if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
                {
                    MComponent->SetXSpeed(0.0f);
                }
                break;
            }
            case InputEvent::Key::W:
            {
                if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
                {
                    MComponent->SetYSpeed(0.0f);
                }
                break;
            }
            default:
                break;
            }

            break;
        }
        default:
            break;
        }
    }
}