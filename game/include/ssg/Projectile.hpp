#pragma once

#include "ssg/Pawn.hpp"

namespace ssg
{
    class Projectile : public Pawn
    {
    public:
        using Ptr = SharedPtr<Projectile>;

        Projectile(const String& InTexturePath, const Transform& InTransform);
        virtual ~Projectile();

        void SetSpeed(const float InSpeed);
        float GetSpeed() const;

        void SetAcceleration(const Vector2D& InAcceleration);
        const Vector2D& GetAcceleration() const;

    };
}