#include "ssg/Pawn.hpp"
#include "ssg/TransformComponent.hpp"
#include "ssg/MeshComponent.hpp"
#include "ssg/MoveComponent.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/ScriptSubSystem.hpp"
#include "sol/sol.hpp"
#include "ssg/WeaponComponent.hpp"
#include "ssg/InputListenerComponent.hpp"
#include "ssg/CollisionComponent.hpp"

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
                        SState->new_usertype<Pawn>("Pawn", sol::constructors<Pawn(const String&, const Transform&, const int), Pawn(const String&, const Transform&, const String&, const float, const int, const int)>(), sol::base_classes, sol::bases<GameObject, Object>(),
                                                   "visible", sol::property(&Pawn::GetVisibleInGame, &Pawn::SetVisibleInGame),
                                                   "transform", sol::property(&Pawn::GetTransform, &Pawn::SetTransform));
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

    Pawn::Pawn(const String& InTexturePath, const Transform& InTransform, const int InLayer)
    {
        TransformComponent::Ptr TComponent = AddNewComponent<TransformComponent>();
        auto MComponent = AddNewComponent<MeshComponent>(InTexturePath);
        if(MComponent)
        {
            TComponent->SetTransform(InTransform);
            MComponent->AddComponent<TransformComponent>(TComponent);
        }

        if (MoveComponent::Ptr MoveObjectComponent = AddNewComponent<MoveComponent>())
        {
            MoveObjectComponent->AddComponent<TransformComponent>(TComponent);
        }

        if (CollisionComponent::Ptr CComponent = AddNewComponent<CollisionComponent>(static_cast<CollisionComponent::Layer>(InLayer)))
        {
            CComponent->AddComponent<MeshComponent>(MComponent);
        }
    }

    Pawn::Pawn(const String& InTexturePath, const Transform& InTransform, const String& InBulletMesh, const float InBulletSpeed, const int InLayer, const int InWeaponLayer)
    {
        TransformComponent::Ptr TComponent = AddNewComponent<TransformComponent>();
        auto MComponent = AddNewComponent<MeshComponent>(InTexturePath);
        if(MComponent)
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
            decltype(auto) WComponent = AddNewComponent<WeaponComponent>(this, InBulletMesh, InBulletSpeed, InWeaponLayer);
            Listener->AddCallback(InputEvent::Type::MouseLeftButtonReleased, Bind(&WeaponComponent::OnMouseLeftButtonReleased, WComponent.get(), Placeholder1));
        }

        if (CollisionComponent::Ptr CComponent = AddNewComponent<CollisionComponent>(static_cast<CollisionComponent::Layer>(InLayer)))
        {
            CComponent->AddComponent<MeshComponent>(MComponent);
            //CComponent->SetOnCollisionEnter([]() { this->MarkForDelete(); });
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

    void Pawn::SetTransform(const Transform& InTransform)
    {
        if (TransformComponent::Ptr TrComponent = GetComponent<TransformComponent>())
        {
            TrComponent->SetTransform(InTransform);
        }
    }

    const Transform& Pawn::GetTransform() const
    {
        if (TransformComponent::Ptr TrComponent = GetComponent<TransformComponent>())
        {
            return TrComponent->GetTransform();
        }

        static Transform s_ZeroTransform = {};
        return s_ZeroTransform;
    }
}