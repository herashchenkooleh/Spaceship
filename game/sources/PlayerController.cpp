#include "ssg/PlayerController.hpp"
#include "ssg/MoveComponent.hpp"
#include "ssg/TransformComponent.hpp"
#include "ssg/InputListenerComponent.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "ssg/PlayerControllerScript.hpp"
#include "sol/sol.hpp"

namespace ssg
{
    /*static*/ bool PlayerController::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<PlayerController>("PlayerController", sol::base_classes, sol::bases<GameObject>(),
                                                               "speed", &PlayerController::m_Speed);
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

    PlayerController::PlayerController()
        : m_Object(nullptr)
    {
        const Vector<InputEvent::Type> ListenEvents = { InputEvent::Type::KeyPressed, InputEvent::Type::KeyReleased, InputEvent::Type::MouseMove };
        InputListenerComponent::Ptr Listener = AddNewComponent<InputListenerComponent>();

        Listener->SetListenEventTypes(ListenEvents);

        Listener->AddCallback(InputEvent::Type::KeyPressed, Bind(&PlayerController::OnKeyPressed, this, Placeholder1));
        Listener->AddCallback(InputEvent::Type::KeyReleased, Bind(&PlayerController::OnKeyReleased, this, Placeholder1));
        Listener->AddCallback(InputEvent::Type::MouseMove, Bind(&PlayerController::OnMouseMove, this, Placeholder1));
    }
    
    PlayerController::~PlayerController() = default;

    bool PlayerController::Initialize(const String& InScriptPath, GameObject::Ptr InObject)
    {
        if (!InObject)
        {
            return false;
        }

        m_Object = InObject;

        PlayerControllerScript Script(DynamicPointerCast<PlayerController>(SharedFromThis(this)));
        return Script.Execute(InScriptPath);
    }

    void PlayerController::Deinitialize()
    {
        m_MousePosition = { 0.0f, 0.0f };
        m_Acceleration = { 0.0f, 0.0f };
        m_Speed = 0.0f;
        m_Object.reset();
    }

    /*virtual*/ void PlayerController::Update(const float InDeltaTime) /*override*/
    {
        if (!m_Object)
        {
            return;
        }

        if (MoveComponent::Ptr MComponent = m_Object->GetComponent<MoveComponent>())
        {
            MComponent->SetSpeed(m_Speed);
            MComponent->SetAcceleration(m_Acceleration);
            if (TransformComponent::Ptr TComponent = m_Object->GetComponent<TransformComponent>())
            {
                Transform& CurrentTransform = TComponent->GetTransform();
                Vector2D Forward = m_MousePosition - CurrentTransform.GetPosition();
                const float PI = 3.14159265;
                float Angle = ((atan2(Forward.GetY(), Forward.GetX())) * 180 / PI) + 90.0f;
                CurrentTransform.SetRotation(Angle);
                Forward.Normalize();
                MComponent->SetLookAt(Forward);
            }
        }
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
            m_Acceleration.SetX(-1.0);
            break;
        }
        case InputEvent::Key::S:
        {
            m_Acceleration.SetY(1.0f);
            break;
        }
        case InputEvent::Key::D:
        {
            m_Acceleration.SetX(1.0f);
            break;
        }
        case InputEvent::Key::W:
        {
            m_Acceleration.SetY(-1.0f);
            break;
        }
        default:
            break;
        }
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
            m_Acceleration.SetX(0.0f);
            break;
        }
        case InputEvent::Key::S:
        {
            m_Acceleration.SetY(0.0f);
            break;
        }
        case InputEvent::Key::D:
        {
            m_Acceleration.SetX(0.0);
            break;
        }
        case InputEvent::Key::W:
        {
            m_Acceleration.SetY(0.0f);
            break;
        }
        default:
            break;
        }
    }

    void PlayerController::OnMouseMove(const InputEvent& InEvent)
    {
        if (!m_Object)
        {
            return;
        }

        m_MousePosition = InEvent.GetMousePosition();
    }
}
