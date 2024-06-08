#include "ssg/GameWindow.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/GameLoop.hpp"
#include "ssg/Configs.hpp"

int main(int argc, const char * argv[])
{
    using namespace ssg;

    ssg::Configs::GetInstance().SetSetting<ssg::String>("filesystem.launch_directory", argv[0]);

     GameWindow::Ptr Window = MakeShared<GameWindow>();
    if (!Window || !Window->Create(800, 600, "SpaceShip"))
    {
        return -1;
    }

    if (!ssg::GameEngine::GetInstance().Initialize(Window))
    {
        return -1;
    }

    int ExitStatus = 0;
    try
    {
        GameLoop::Ptr Loop = MakeShared<GameLoop>();
        if (!Loop || !Loop->Initialize())
        {
            return -1;
        }

        Loop->Start();
    }
    catch(...)
    {
        ExitStatus = -1;
    }
    
    ssg::GameEngine::GetInstance().Deinitialize();

    return ExitStatus;
}