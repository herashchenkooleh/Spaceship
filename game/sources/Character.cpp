#include "ssg/Character.hpp"
#include "ssg/ScaleComponent.hpp"
#include "ssg/RotationComponent.hpp"
#include "ssg/PositionComponent.hpp"
#include "ssg/MeshComponent.hpp"
#include "ssg/MoveComponent.hpp"

namespace ssg
{
    Character::Character(const String& InTexturePath)
        : m_TexturePath(InTexturePath)
    {

    }

    /*virtual*/ Character::~Character() = default;

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
            MComponent->AddComponent<ScaleComponent>(SComponent);
            MComponent->AddComponent<RotationComponent>(RComponent);
            MComponent->AddComponent<PositionComponent>(PosComponent);
        }

        if (MoveComponent::Ptr MoveObjectComponent = AddComponent<MoveComponent>())
        {
            MoveObjectComponent->AddComponent<ScaleComponent>(SComponent);
            MoveObjectComponent->AddComponent<RotationComponent>(RComponent);
            MoveObjectComponent->AddComponent<PositionComponent>(PosComponent);
        }

        return true;
    }
}