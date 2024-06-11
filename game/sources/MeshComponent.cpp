#include "ssg/MeshComponent.hpp"

namespace ssg
{
    MeshComponent::MeshComponent(const String InTexture)
        : m_Texture(InTexture)
        , m_Visible(true)
    {

    }

    MeshComponent::~MeshComponent() = default;

    const String& MeshComponent::GetTexture() const
    {
        return m_Texture;
    }
}