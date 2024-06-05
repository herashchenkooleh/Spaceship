#include "Renderer.hpp"
#include "SFML/Graphics.hpp"

namespace SpaceShipGame
{
    struct Drawable
    {
        sf::Texture m_Texture;
        sf::Sprite m_Sprite;
        MeshComponent::Ptr m_MeshComponent;

        Drawable(MeshComponent::Ptr InMeshComponent, sf::Texture DefaultTexture);
        ~Drawable();
    };

    Drawable::Drawable(MeshComponent::Ptr InMeshComponent, sf::Texture DefaultTexture)
        : m_Sprite(DefaultTexture)
    {
        m_MeshComponent = InMeshComponent;
        if (m_MeshComponent)
        {
            if (m_Texture.loadFromFile(InMeshComponent->GetTexture()))
            {
                m_Sprite.setTexture(m_Texture);
            }
        }
    }

    Drawable::~Drawable() = default;

    struct Renderer::Implementation
    {
        sf::Texture m_EmptyTexture;
        sf::RenderWindow *m_HwRenderTarget;
        Map<Object::Identifier, Drawable> m_Meshes;
    };

    Renderer::Renderer()
        : m_Implementation(MakeShared<Implementation>())
    {
    }

    Renderer::~Renderer() = default;

    bool Renderer::Initialize(GameWindow::Ptr InWindow)
    {
        if (!InWindow)
        {
            return false;
        }

        m_Implementation->m_HwRenderTarget = reinterpret_cast<sf::RenderWindow *>(InWindow->GetRenderTarget());

        return true;
    }

    void Renderer::Draw(const float InInterpolation)
    {
        m_Implementation->m_HwRenderTarget->clear();

        for (auto [Identifier, Mesh] : m_Implementation->m_Meshes)
        {
            PositionComponent::Ptr PosComponent = Mesh.m_MeshComponent->GetComponent<PositionComponent>();
            if (PosComponent)
            {
                //TODO Scale and Rotation
                Vector2D Position = PosComponent->GetPosition();
                Mesh.m_Sprite.setPosition({ Position.GetX(), Position.GetY() });
            }
            m_Implementation->m_HwRenderTarget->draw(Mesh.m_Sprite);
        }

        m_Implementation->m_HwRenderTarget->display();
    }

    void Renderer::Register(MeshComponent::Ptr InMesh)
    {
        m_Implementation->m_Meshes.insert( { InMesh->GetID(), { InMesh, m_Implementation->m_EmptyTexture } });
    }

    void Renderer::Unregister(MeshComponent::Ptr InMesh)
    {
    }
}