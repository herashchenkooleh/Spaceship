#include "Renderer.hpp"
#include "SFML/Graphics.hpp"
#include "ScaleComponent.hpp"
#include "RotationComponent.hpp"
#include "PositionComponent.hpp"

namespace SpaceShipGame
{
    struct Drawable
    {
        SharedPtr<sf::Texture> m_Texture;
        SharedPtr<sf::Sprite> m_Sprite;
        MeshComponent::Ptr m_MeshComponent;

        Drawable();
        ~Drawable();

        bool Initialize(MeshComponent::Ptr InMeshComponent);
    };

    Drawable::Drawable()
        : m_Texture(nullptr)
        , m_Sprite(nullptr)
        , m_MeshComponent(nullptr)
    {

    }

    Drawable::~Drawable() = default;

    bool Drawable::Initialize(MeshComponent::Ptr InMeshComponent)
    {
        m_Texture = MakeShared<sf::Texture>();

        m_MeshComponent = InMeshComponent;
        if (m_MeshComponent)
        {
            if (m_Texture->loadFromFile(InMeshComponent->GetTexture()))
            {
                m_Sprite = MakeShared<sf::Sprite>(*m_Texture.get());
                m_Sprite->setOrigin(sf::Vector2f(m_Sprite->getLocalBounds().width, m_Sprite->getLocalBounds().height) / 2.f);

                return true;
            }
        }

        return false;
    }

    struct Renderer::Implementation
    {
        sf::RenderWindow *m_HwRenderTarget;
        Map<Object::Identifier, SharedPtr<Drawable>> m_Meshes;
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

        m_Implementation->m_HwRenderTarget = reinterpret_cast<sf::RenderWindow*>(InWindow->GetRenderTarget());

        return true;
    }

    void Renderer::Draw(const float InInterpolation)
    {
        m_Implementation->m_HwRenderTarget->clear();
        
        for (auto [Identifier, Mesh] : m_Implementation->m_Meshes)
        {
            if (ScaleComponent::Ptr SComponent = Mesh->m_MeshComponent->GetComponent<ScaleComponent>())
            {
                Vector2D Scale = SComponent->GetScale();
                Mesh->m_Sprite->setScale({ Scale.GetX(), Scale.GetY() });
            }

            if (RotationComponent::Ptr RComponent = Mesh->m_MeshComponent->GetComponent<RotationComponent>())
            {
                Mesh->m_Sprite->setRotation(sf::degrees(RComponent->GetDegrees()));
            }

            if (PositionComponent::Ptr PosComponent = Mesh->m_MeshComponent->GetComponent<PositionComponent>())
            {
                Vector2D Position = PosComponent->GetPosition();
                Mesh->m_Sprite->setPosition({ Position.GetX(), Position.GetY() });
            }
            
            m_Implementation->m_HwRenderTarget->draw(*Mesh->m_Sprite.get());
        }
        m_Implementation->m_HwRenderTarget->display();
    }

    void Renderer::Register(MeshComponent::Ptr InMesh)
    {
        auto DrawableItem = MakeShared<Drawable>();
        if (DrawableItem->Initialize(InMesh))
        {
            m_Implementation->m_Meshes.insert( { InMesh->GetID(), DrawableItem });
        }
    }

    void Renderer::Unregister(MeshComponent::Ptr InMesh)
    {
    }
}
