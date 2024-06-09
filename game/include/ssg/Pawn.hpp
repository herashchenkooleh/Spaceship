#pragma once

#include "ssg/Vector2D.hpp"
#include "ssg/GameObject.hpp"

namespace ssg
{
    class Pawn : public GameObject
    {
    public:
        using Ptr = SharedPtr<Pawn>;

        Pawn(const String& InTexturePath);
        virtual ~Pawn();

        virtual bool Construct() override;   

    private:
        String m_TexturePath; 
    };
}
