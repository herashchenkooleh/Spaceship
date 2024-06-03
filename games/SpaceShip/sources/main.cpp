#include "GameWindow.hpp"
#include "InputManager.hpp"
#include "GameLoop.hpp"

#include <iostream>

int main()
{
    using namespace SpaceShipGame;

    GameWindow::Ptr Window = MakeShared<GameWindow>();
    if (!Window || !Window->Create(800, 600, "SpaceShip"))
    {
        std::cout << "Failed create game window" << std::endl;
        return -1;
    }

    InputManager::Ptr InpManager = MakeShared<InputManager>();
    if (!InpManager || !InpManager->Initialize())
    {
        return -1;
    }

    GameLoop::Ptr Loop = MakeShared<GameLoop>();
    if (!Loop || !Loop->Initialize(Window, InpManager))
    {
        std::cout << "Failed create game loop" << std::endl;
        return -1;
    }

    Loop->Start();
    
    Loop->Deinitialize();

    return 0;
}