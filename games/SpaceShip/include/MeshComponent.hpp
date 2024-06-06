#pragma once

#include "Vector2D.hpp"
#include "GameObjectComponent.hpp"

namespace SpaceShipGame
{
    class MeshComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<MeshComponent>;

        MeshComponent(const String InTexture);
        ~MeshComponent();

        const String& GetTexture() const;

    private:
        String m_Texture;
    };
}