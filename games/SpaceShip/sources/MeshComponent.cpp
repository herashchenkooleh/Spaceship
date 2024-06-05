#include "MeshComponent.hpp"

namespace SpaceShipGame
{
    MeshComponent::MeshComponent(const String InTexture)
        : m_Texture(InTexture)
    {

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
}