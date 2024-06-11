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
        virtual ~Pawn();

        virtual bool Construct() override;

        static bool RegisterScriptType();

    private:
        String m_TexturePath;
        Transform m_SpawnTransform;
    };
}
