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
}