#include "ssg/RenderSubSystem.hpp"

namespace ssg
{
    RenderSubSystem::RenderSubSystem(GameWindow::Ptr InWindow)
        : m_Renderer(MakeShared<Renderer>(InWindow))
    {

    }
    /*virtual*/ RenderSubSystem::~RenderSubSystem() = default;

    /*virtual*/ bool RenderSubSystem::Initialize() /*override*/
    {
        return true;
    }

    /*virtual*/ void RenderSubSystem::Update(const float InDeltaTime) /*override*/
    {

    }

    /*virtual*/ void RenderSubSystem::Deinitialize() /*override*/
    {

    }

    /*virtual*/ void RenderSubSystem::RegisterGameObject(GameObject::Ptr InObject) /*override*/
    {
        if (MeshComponent::Ptr Mesh = InObject->GetComponent<MeshComponent>())
        {
            m_Renderer->Register(Mesh);
        }
    }

    /*virtual*/ void RenderSubSystem::UnregisterGameObject(GameObject::Ptr InObject) /*override*/
    {
        if (MeshComponent::Ptr Mesh = InObject->GetComponent<MeshComponent>())
        {
            m_Renderer->Unregister(Mesh);
        }
    }
}