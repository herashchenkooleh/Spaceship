#include "ssg/PlayerController.hpp"
#include "ssg/MoveComponent.hpp"
#include "ssg/TransformComponent.hpp"
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
        if (!InObject)
        {
            return false;
        }

        m_Object = InObject;

        return true;
    }

    void PlayerController::Deinitialize()
    {
        m_MousePosition = { 0.0f, 0.0f };
        m_Speed = { 0.0f, 0.0f };
        m_Object.reset();
    }

    /*virtual*/ bool PlayerController::Construct() /*override*/
    {
        const Vector<InputEvent::Type> ListenEvents = { InputEvent::Type::KeyPressed, InputEvent::Type::KeyReleased, InputEvent::Type::MouseMove  };
        InputListenerComponent::Ptr Listener = AddComponent<InputListenerComponent>(ListenEvents);

        Listener->AddCallback(InputEvent::Type::KeyPressed, Bind(&PlayerController::OnKeyPressed, this, Placeholder1));
        Listener->AddCallback(InputEvent::Type::KeyReleased, Bind(&PlayerController::OnKeyReleased, this, Placeholder1));
        Listener->AddCallback(InputEvent::Type::MouseMove, Bind(&PlayerController::OnMouseMove, this, Placeholder1));

        return true;
    }

    /*virtual*/ bool PlayerController::Destroy() /*override*/
    {
        return true;
    }

    void PlayerController::OnKeyPressed(const InputEvent& InEvent)
    {
        if (!m_Object)
        {
            return;
        }

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
        if (!m_Object)
        {
            return;
        }

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
        if (!m_Object)
        {
            return;
        }

        m_MousePosition = InEvent.GetMousePosition();
        UpdatePosition();
    }

    void PlayerController::UpdatePosition()
    {
        if (!m_Object)
        {
            return;
        }

        if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
        {
            MComponent->SetSpeed(m_Speed);
            if (TransformComponent::Ptr TComponent = m_Object->GetComponent<TransformComponent>())
            {
                Transform& CurrentTransform = TComponent->GetTransform();
                Vector2D Forward = m_MousePosition - CurrentTransform.GetPosition();
                const float PI = 3.14159265;
                float Angle = ((atan2(Forward.GetY(), Forward.GetX())) * 180 / PI) + 90.0f;
                CurrentTransform.SetRotation(Angle);
            }
        }
    }
}
