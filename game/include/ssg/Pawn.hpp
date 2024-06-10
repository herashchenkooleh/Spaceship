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

    private:
        String m_TexturePath;
        Transform m_Transform;
    };
}
