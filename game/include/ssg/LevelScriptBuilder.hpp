#pragma once

#include "ssg/Level.hpp"
#include "ssg/IScriptBuilder.hpp"

namespace ssg
{
    class LevelScriptBuilder : public IScriptBuilder
    {
    public:
        LevelScriptBuilder(const String& InLvlScript, Level::Ptr InLevel);
        virtual ~LevelScriptBuilder();

        virtual bool ExecuteScript() override;

    private:
        String m_LvlScript;
        Level::Ptr m_Level;
    };
}