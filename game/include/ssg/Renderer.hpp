#pragma once

#include "Global.hpp"
#include "GameWindow.hpp"
#include "MeshComponent.hpp"

namespace ssg
{
    class Renderer
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<Renderer>;

        Renderer(GameWindow::Ptr InWindow);
        ~Renderer();

        void Draw(const float InInterpolation);

        void Register(MeshComponent::Ptr InMesh);
        void Unregister(MeshComponent::Ptr InMesh);

    private:
        ImplementationPtr m_Implementation;
    };
}