#include "ssg/PlayerController.hpp"
#include "ssg/MoveComponent.hpp"
#include "ssg/PositionComponent.hpp"

namespace ssg
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
                m_Speed.SetX(-3.0);
                break;
            }
            case InputEvent::Key::S:
            {
                m_Speed.SetY(3.0f);
                break;
            }
            case InputEvent::Key::D:
            {
                m_Speed.SetX(3.0f);
                break;
            }
            case InputEvent::Key::W:
            {
                m_Speed.SetY(-3.0f);
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
                m_Speed.SetX(0.0f);
                break;
            }
            case InputEvent::Key::S:
            {
                m_Speed.SetY(0.0f);
                break;
            }
            case InputEvent::Key::D:
            {
                m_Speed.SetX(0.0);
                break;
            }
            case InputEvent::Key::W:
            {
                m_Speed.SetY(0.0f);
                break;
            }
            default:
                break;
            }

            break;
        }
        case InputEvent::Type::MouseMove:
        {
            m_MousePosition = InEvent.GetMousePosition();
                    
                    
            break;
        }
        default:
            break;
        }
        
        UpdatePosition();
    }

    void PlayerController::UpdatePosition()
    {
        if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
        {
            MComponent->SetSpeed(m_Speed);
            if (PositionComponent::Ptr PosComponent = m_Object->GetComponent<PositionComponent>())
            {
                Vector2D Forward = m_MousePosition - PosComponent->GetPosition();
                const float PI = 3.14159265;
                float Angle = ((atan2(Forward.GetY(), Forward.GetX())) * 180 / PI) + 90.0f;
                MComponent->SetRotation(Angle);
            }
        }
    }
}
