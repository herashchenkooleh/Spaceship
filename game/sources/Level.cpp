#include "ssg/Level.hpp"
#include "ssg/LevelScriptBuilder.hpp"

namespace ssg
{
    Level::Level()
    {

    }
    
    /*virtual*/ Level::~Level() = default;

    bool Level::Load(const String& InLvlScript)
    {
        LevelScriptBuilder Builder = { InLvlScript, SharedFromThis(this) };

        return Builder.ExecuteScript();
    }
}