#pragma once

#include "ssg/Global.hpp"
#include "ssg/GameWindow.hpp"
#include "ssg/MeshComponent.hpp"

namespace ssg
{
    class Renderer
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<Renderer>;

        Renderer();
        ~Renderer();

        bool Initialize(GameWindow::Ptr InWindow);
        void Draw(const float InInterpolation);

        void Register(MeshComponent::Ptr InMesh);
        void Unregister(MeshComponent::Ptr InMesh);

    private:
        ImplementationPtr m_Implementation;
    };
}