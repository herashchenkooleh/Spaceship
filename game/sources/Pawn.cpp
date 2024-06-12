#include "ssg/Pawn.hpp"
#include "ssg/TransformComponent.hpp"
#include "ssg/MeshComponent.hpp"
#include "ssg/MoveComponent.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"
#include "ssg/WeaponComponent.hpp"
#include "ssg/InputListenerComponent.hpp"

namespace ssg
{
    /*static*/ bool Pawn::RegisterScriptType()
    {
        try
        {
            if(ScriptSubSystem::Ptr SSubSystem = GameEngine::GetInstance().GetSubSystem<ScriptSubSystem>())
            {
                if (ScriptManager::Ptr SManager = SSubSystem->GetManager())
                {
                    if (sol::state* SState = reinterpret_cast<sol::state*>(SManager->GetScriptContent()))
                    {
                        SState->new_usertype<Pawn>("Pawn", sol::constructors<Pawn(const String&, const Transform&), Pawn(const String&, const Transform&, const String&, const float)>(), sol::base_classes, sol::bases<GameObject>(),
                                                   "visibile", sol::property(&Pawn::GetVisibleInGame, &Pawn::SetVisibleInGame));
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

    Pawn::Pawn(const String& InTexturePath, const Transform& InTransform)
    {
        TransformComponent::Ptr TComponent = AddNewComponent<TransformComponent>();
        if(auto MComponent = AddNewComponent<MeshComponent>(InTexturePath))
        {
            TComponent->SetTransform(InTransform);
            MComponent->AddComponent<TransformComponent>(TComponent);
        }

        if (MoveComponent::Ptr MoveObjectComponent = AddNewComponent<MoveComponent>())
        {
            MoveObjectComponent->AddComponent<TransformComponent>(TComponent);
        }
    }

    Pawn::Pawn(const String& InTexturePath, const Transform& InTransform, const String& InBulletMesh, const float InBulletSpeed)
    {
        TransformComponent::Ptr TComponent = AddNewComponent<TransformComponent>();
        if(auto MComponent = AddNewComponent<MeshComponent>(InTexturePath))
        {
            TComponent->SetTransform(InTransform);
            MComponent->AddComponent<TransformComponent>(TComponent);
        }

        if (MoveComponent::Ptr MoveObjectComponent = AddNewComponent<MoveComponent>())
        {
            MoveObjectComponent->AddComponent<TransformComponent>(TComponent);

            const Vector<InputEvent::Type> ListenEvents = { InputEvent::Type::MouseLeftButtonReleased };
            InputListenerComponent::Ptr Listener = AddNewComponent<InputListenerComponent>();
            Listener->SetListenEventTypes(ListenEvents);
            decltype(auto) WComponent = AddNewComponent<WeaponComponent>(this, InBulletMesh, InBulletSpeed);
            Listener->AddCallback(InputEvent::Type::MouseLeftButtonReleased, Bind(&WeaponComponent::OnMouseLeftButtonReleased, WComponent.get(), Placeholder1));
        }
    }

    /*virtual*/ Pawn::~Pawn() = default;

    void Pawn::SetVisibleInGame(const bool InVisibility)
    {
        if(auto MComponent = GetComponent<MeshComponent>())
        {
            MComponent->SetVisible(InVisibility);
        }
    }

    bool Pawn::GetVisibleInGame() const
    {
        if(auto MComponent = GetComponent<MeshComponent>())
        {
            return MComponent->IsVisible();
        }

        return false;
    }
}