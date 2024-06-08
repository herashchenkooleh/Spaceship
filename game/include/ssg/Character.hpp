#pragma once

#include "ssg/Actor.hpp"

namespace ssg
{
    class Character : public Actor
    {
    public:
        using Ptr = SharedPtr<Character>;

        Character(const String& InTexturePath);
        ~Character();

        virtual bool Construct() override;   

    private:
        String m_TexturePath; 
    };
}
