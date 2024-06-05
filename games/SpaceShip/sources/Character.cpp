#include "Character.hpp"
#include "PositionComponent.hpp"
#include "MeshComponent.hpp"
#include <iostream>
namespace SpaceShipGame
{
    Character::Character(const String& InTexturePath)
        : m_TexturePath(InTexturePath)
    {

    }

    Character::~Character() = default;

    /*virtual*/ bool Character::Construct() /*override*/
    {
        if (!Actor::Construct())
        {
            return false;
        }

        PositionComponent::Ptr PosComponent = GetComponent<PositionComponent>();
        AddComponent<MeshComponent>(m_TexturePath, PosComponent);
        
        std::cout << "Constract character" << m_Components.size() << std::endl;

        return true;
    }
}