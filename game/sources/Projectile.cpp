#include "ssg/Projectile.hpp"
#include "ssg/MoveComponent.hpp"
#include "ssg/TransformComponent.hpp"
#include "ssg/GameEngine.hpp"

namespace ssg
{
    Projectile::Projectile(const String& InTexturePath, const Transform& InTransform, const int InLayer)
        : Pawn(InTexturePath, InTransform, InLayer)
    {

    }

    /*virtual*/ Projectile::~Projectile() = default;

    /*virtual*/ void Projectile::Update(const float InDeltaTime) /*override*/
    {
        Pawn::Update(InDeltaTime);

        if(MoveComponent::Ptr MComponent = GetComponent<MoveComponent>())
        {
            if (TransformComponent::Ptr TComponent = GetComponent<TransformComponent>())
            {
                decltype(auto) WindowSize = GameEngine::GetInstance().GetWindowSize();
                decltype(auto) Position = TComponent->GetTransform().GetPosition();

                if (Position.GetX() < 0 || Position.GetY() < 0 || Position.GetX() > WindowSize.GetX() || Position.GetY() > WindowSize.GetY())
                {
                    MarkForDelete();
                    return;
                }
            }
        }
    }

    void Projectile::SetSpeed(const float InSpeed)
    {
        if(MoveComponent::Ptr MComponent = GetComponent<MoveComponent>())
        {
            MComponent->SetSpeed(InSpeed);
        }
    }

    float Projectile::GetSpeed() const
    {
        if (MoveComponent::Ptr MComponent = GetComponent<MoveComponent>())
        {
            return MComponent->GetSpeed();
        }

        return 0.0f;
    }

    void Projectile::SetAcceleration(const Vector2D& InAcceleration)
    {
        if(MoveComponent::Ptr MComponent = GetComponent<MoveComponent>())
        {
            MComponent->SetAcceleration(InAcceleration);
        }
    }

    const Vector2D& Projectile::GetAcceleration() const
    {
        if (MoveComponent::Ptr MComponent = GetComponent<MoveComponent>())
        {
            return MComponent->GetAcceleration();
        }

        static Vector2D s_ZeroSpeed = { 0.0f, 0.0f };
        return s_ZeroSpeed;
    }
}