#include "MeshComponent.hpp"

namespace SpaceShipGame
{
    MeshComponent::MeshComponent(const String InTexture, PositionComponent::Ptr InPositionComponent)
        : m_Texture(InTexture)
    {
        AddComponent<PositionComponent>(InPositionComponent);
    }

    MeshComponent::~MeshComponent() = default;

    /*virtual*/ bool MeshComponent::Construct()
    {
        return true;
    }

    /*virtual*/ bool MeshComponent::Destroy()
    {
        return true;
    }

    const String& MeshComponent::GetTexture() const
    {
        return m_Texture;
    }

    const Vector2D& MeshComponent::GetPosition() const
    {
        if (PositionComponent::Ptr PosComponent = GetComponent<PositionComponent>(); PosComponent != nullptr)
        {
            return PosComponent->GetPosition();
        }

        static Vector2D s_EmptyPosition;
        return s_EmptyPosition;
    }
}