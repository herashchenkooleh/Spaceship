#include "ssg/Pawn.hpp"
#include "ssg/TransformComponent.hpp"
#include "ssg/MeshComponent.hpp"
#include "ssg/MoveComponent.hpp"

namespace ssg
{
    Pawn::Pawn(const String& InTexturePath, const Transform& InTransform)
        : m_TexturePath(InTexturePath)
        , m_Transform(InTransform)
    {

    }

    /*virtual*/ Pawn::~Pawn() = default;

    /*virtual*/ bool Pawn::Construct() /*override*/
    {
        TransformComponent::Ptr TComponent = AddComponent<TransformComponent>();
        if(auto MComponent = AddComponent<MeshComponent>(m_TexturePath))
        {
            TComponent->SetTransform(m_Transform);
            MComponent->AddComponent<TransformComponent>(TComponent);
        }

        if (MoveComponent::Ptr MoveObjectComponent = AddComponent<MoveComponent>())
        {
            MoveObjectComponent->AddComponent<TransformComponent>(TComponent);
        }

        return true;
    }
}