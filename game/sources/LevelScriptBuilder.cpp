#include "ssg/LevelScriptBuilder.hpp"

namespace ssg
{
    LevelScriptBuilder::LevelScriptBuilder(const String& InLvlScript, Level::Ptr InLevel)
        : m_LvlScript(InLvlScript)
        , m_Level(InLevel)
    {
        
    }

    /*virtual*/ LevelScriptBuilder::~LevelScriptBuilder() = default;

    /*virtual*/ bool LevelScriptBuilder::ExecuteScript() /*override*/
    {
        return true;
    }
}