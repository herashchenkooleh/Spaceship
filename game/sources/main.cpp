#include "ssg/GameWindow.hpp"
#include "ssg/GameLoop.hpp"
#include "ssg/World.hpp"
#include "ssg/Renderer.hpp"

int main(int argc, const char * argv[])
{
    using namespace ssg;

    GameWindow::Ptr Window = MakeShared<GameWindow>();
    if (!Window || !Window->Create(800, 600, "SpaceShip"))
    {
        return -1;
    }

    InputManager::Ptr InpManager = MakeShared<InputManager>();
    if (!InpManager || !InpManager->Initialize(Window))
    {
        return -1;
    }

    Renderer::Ptr Render = MakeShared<Renderer>();
    if (!Render || !Render->Initialize(Window))
    {
        return -1;
    }

    World::Ptr PlayWorld = MakeShared<World>();
    if (!PlayWorld || !PlayWorld->Initialize(InpManager, Render))
    {
        return -1;
    }

    World::SetCurrentWorld(PlayWorld);

    GameLoop::Ptr Loop = MakeShared<GameLoop>();
    if (!Loop || !Loop->Initialize(Window, InpManager, PlayWorld, Render))
    {
        return -1;
    }

    Loop->Start();

    Loop->Deinitialize();

    return 0;
}