#include "Character.hpp"
#include "ScaleComponent.hpp"
#include "RotationComponent.hpp"
#include "PositionComponent.hpp"
#include "MeshComponent.hpp"

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

        ScaleComponent::Ptr SComponent = AddComponent<ScaleComponent>();
        SComponent->SetScale({0.07f, 0.07f});
        RotationComponent::Ptr RComponent = AddComponent<RotationComponent>();
        PositionComponent::Ptr PosComponent = GetComponent<PositionComponent>();
        if(auto MComponent = AddComponent<MeshComponent>(m_TexturePath))
        {
            MComponent->AddComponent<RotationComponent>(RComponent);
            MComponent->AddComponent<ScaleComponent>(SComponent);
            MComponent->AddComponent<PositionComponent>(PosComponent);
        }

        return true;
    }
}