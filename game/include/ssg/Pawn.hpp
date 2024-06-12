#pragma once

#include "ssg/Transform.hpp"
#include "ssg/GameObject.hpp"
#include "ssg/CollisionComponent.hpp"

namespace ssg
{
    class Pawn : public GameObject
    {
    public:
        using Ptr = SharedPtr<Pawn>;

        Pawn(const String& InTexturePath, const Transform& InTransform, const int InLayer);
        Pawn(const String& InTexturePath, const Transform& InTransform, const String& InBulletMesh, const float InBulletSpeed, const int InPawnLayer, const int InWeaponLayer);
        virtual ~Pawn();

        static bool RegisterScriptType();

        void SetVisibleInGame(const bool InVisibility);
        bool GetVisibleInGame() const;

        void SetTransform(const Transform& InTransform);
        const Transform& GetTransform() const;
    };
}
