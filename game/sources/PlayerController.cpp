#include "ssg/PlayerController.hpp"
#include "ssg/MoveComponent.hpp"
#include "ssg/PositionComponent.hpp"
#include "ssg/InputListenerComponent.hpp"

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

    /*virtual*/ bool PlayerController::Construct() /*override*/
    {

    }

    /*virtual*/ bool PlayerController::Destroy() /*override*/
    {
        const Vector<InputEvent::Type> ListenEvents = { InputEvent::Type::KeyPressed, InputEvent::Type::KeyReleased, InputEvent::Type::MouseMove  };
        InputListenerComponent::Ptr Listener = AddComponent<InputListenerComponent>(ListenEvents);

        Listener->AddCallback(InputEvent::Type::KeyPressed, Bind(&PlayerController::OnKeyPressed, this, Placeholder1));
        Listener->AddCallback(InputEvent::Type::KeyReleased, Bind(&PlayerController::OnKeyReleased, this, Placeholder1));
        Listener->AddCallback(InputEvent::Type::MouseMove, Bind(&PlayerController::OnMouseMove, this, Placeholder1));
    }

    void PlayerController::OnKeyPressed(const InputEvent& InEvent)
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

        UpdatePosition();
    }

    void PlayerController::OnKeyReleased(const InputEvent& InEvent)
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
        UpdatePosition();
    }

    void PlayerController::OnMouseMove(const InputEvent& InEvent)
    {
        m_MousePosition = InEvent.GetMousePosition();
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
