#include "ssg/Projectile.hpp"
#include "ssg/MoveComponent.hpp"

namespace ssg
{
    Projectile::Projectile(const String& InTexturePath, const Transform& InTransform)
        : Pawn(InTexturePath, InTransform)
    {

    }

    /*virtual*/ Projectile::~Projectile() = default;

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