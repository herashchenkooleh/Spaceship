#pragma once

#include "ssg/ISubSystem.hpp"
#include "ssg/Renderer.hpp"
#include "ssg/GameWindow.hpp"

namespace ssg
{
    class RenderSubSystem : public ISubSystem
    {
    public:
        using Ptr = SharedPtr<RenderSubSystem>;

        RenderSubSystem(GameWindow::Ptr InWindow);
        virtual ~RenderSubSystem();

        virtual bool Initialize() override;
        virtual void Update(const float InDeltaTime) override;
        virtual void Deinitialize() override;

        Renderer::Ptr GetRenderer() { return m_Renderer; }

    private:
        Renderer::Ptr m_Renderer;
    };
}