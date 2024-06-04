#include "GameWindow.hpp"
#include "GameLoop.hpp"
#include "World.hpp"

int main()
{
    using namespace SpaceShipGame;

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

    World::Ptr PlayWorld = MakeShared<World>();
    if (!PlayWorld || !PlayWorld->Initialize(InpManager))
    {
        return -1;
    }

    GameLoop::Ptr Loop = MakeShared<GameLoop>();
    if (!Loop || !Loop->Initialize(Window, InpManager, PlayWorld))
    {
        return -1;
    }

    Loop->Start();

    Loop->Deinitialize();

    return 0;
}