#include "ssg/Renderer.hpp"
#include "ssg/ScaleComponent.hpp"
#include "ssg/RotationComponent.hpp"
#include "ssg/PositionComponent.hpp"

#include "SFML/Graphics.hpp"

namespace ssg
{
    struct Drawable
    {
        std::optional<sf::Texture> m_Texture;
        SharedPtr<sf::Sprite> m_Sprite;
        MeshComponent::Ptr m_MeshComponent;

        Drawable();
        ~Drawable();

        bool Initialize(MeshComponent::Ptr InMeshComponent);
    };

    Drawable::Drawable()
        : m_Texture()
        , m_Sprite(nullptr)
        , m_MeshComponent(nullptr)
    {

    }

    Drawable::~Drawable() = default;

    bool Drawable::Initialize(MeshComponent::Ptr InMeshComponent)
    {
        if (m_Texture.has_value())
        {
            return false;
        }

        m_MeshComponent = InMeshComponent;
        if (m_MeshComponent)
        {
            m_Texture = sf::Texture::loadFromFile(InMeshComponent->GetTexture());
            if (m_Texture.has_value())
            {
                m_Sprite = MakeShared<sf::Sprite>(m_Texture.value());
                m_Sprite->setOrigin(sf::Vector2f(m_Sprite->getLocalBounds().width, m_Sprite->getLocalBounds().height) / 2.f);
                m_Sprite->setPosition({100, 100});

                return true;
            }
        }

        return false;
    }

    struct Renderer::Implementation
    {
        sf::RenderWindow *m_HwRenderTarget;
        Map<Object::Identifier, SharedPtr<Drawable>> m_Meshes;

        Implementation(GameWindow::Ptr InWindow);
        ~Implementation();
    };

    Renderer::Implementation::Implementation(GameWindow::Ptr InWindow)
    {
        if (InWindow)
        {
            m_HwRenderTarget = reinterpret_cast<sf::RenderWindow*>(InWindow->GetRenderTarget());
        }
    }

    Renderer::Implementation::~Implementation() = default;

    Renderer::Renderer(GameWindow::Ptr InWindow)
        : m_Implementation(MakeShared<Implementation>(InWindow))
    {

    }

    Renderer::~Renderer() = default;

    void Renderer::Draw(const float InInterpolation)
    {
        if (!m_Implementation->m_HwRenderTarget)
        {
            return;
        }

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
