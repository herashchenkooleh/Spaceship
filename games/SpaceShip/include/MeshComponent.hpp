#pragma once

#include "Vector2D.hpp"
#include "PositionComponent.hpp"
#include "GameObjectComponent.hpp"

namespace SpaceShipGame
{
    class MeshComponent : public GameObjectComponent
    {
    public:
        using Ptr = SharedPtr<MeshComponent>;

        MeshComponent(const String InTexture, PositionComponent::Ptr InPositionComponent);
        ~MeshComponent();

        virtual bool Construct();
        virtual bool Destroy();

        const String& GetTexture() const;
        const Vector2D& GetPosition() const;

    private:
        String m_Texture;
    };
}