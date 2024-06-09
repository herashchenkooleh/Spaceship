#include "ssg/GameWindow.hpp"
#include "ssg/GameEngine.hpp"
#include "ssg/GameLoop.hpp"
#include "ssg/Configs.hpp"

#include "ssg/FileSystemHelper.hpp"

int main(int argc, const char * argv[])
{
    using namespace ssg;

    ssg::Configs::GetInstance().SetSetting<ssg::String>(ssg::Configs::s_GlobalRelBinaryPathSettingName, argv[0]);
    ssg::Configs::GetInstance().SetSetting<ssg::String>(ssg::Configs::s_GlobalRelAssetsPathSettingName, "assets");
    ssg::Configs::GetInstance().SetSetting<ssg::String>(ssg::Configs::s_GlobalDefaultShellGameStateSettingName, "DefaultShellScript.lua");
    ssg::Configs::GetInstance().SetSetting<ssg::String>(ssg::Configs::s_GlobalDefaultMissionGameStateSettingName, "DefaultMissionScript.lua");

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