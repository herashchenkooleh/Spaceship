#pragma once

#include "ssg/Transform.hpp"
#include "ssg/GameObject.hpp"

namespace ssg
{
    class Pawn : public GameObject
    {
    public:
        using Ptr = SharedPtr<Pawn>;

        Pawn(const String& InTexturePath, const Transform& InTransform);
        Pawn(const String& InTexturePath, const Transform& InTransform, const String& InBulletMesh, const float InBulletSpeed);
        virtual ~Pawn();

        static bool RegisterScriptType();

        void SetVisibleInGame(const bool InVisibility);
        bool GetVisibleInGame() const;
    };
}
