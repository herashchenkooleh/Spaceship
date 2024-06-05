#pragma once

#include "Actor.hpp"

namespace SpaceShipGame
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
