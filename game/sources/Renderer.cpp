#include "ssg/Renderer.hpp"
#include "ssg/TransformComponent.hpp"
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
                m_Texture->setSmooth(true);
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
            if (TransformComponent::Ptr TrComponent = Mesh->m_MeshComponent->GetComponent<TransformComponent>())
            {
                sf::Vector2u OriginSize = Mesh->m_Texture->getSize();
                const Transform& CurrentTransform = TrComponent->GetTransform();

                // TODO origin normalize
                Vector2D SpriteSize = { static_cast<float>(Mesh->m_Sprite->getLocalBounds().width), static_cast<float>(Mesh->m_Sprite->getLocalBounds().height) };
                Vector2D Origin = SpriteSize * CurrentTransform.GetOrigin();
                Mesh->m_Sprite->setOrigin({ Origin.GetX(), Origin.GetY() });
 
                Vector2D Scale = CurrentTransform.GetSize() / Vector2D{ static_cast<float>(OriginSize.x), static_cast<float>(OriginSize.y) };

                Mesh->m_Sprite->setScale({ Scale.GetX(), Scale.GetY() });
                Mesh->m_Sprite->setRotation(sf::degrees(CurrentTransform.GetRotation()));
                Vector2D Position = CurrentTransform.GetPosition();
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
