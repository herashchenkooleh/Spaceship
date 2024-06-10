#pragma once

#include "ssg/Level.hpp"
#include "ssg/IScript.hpp"

namespace ssg
{
    class LevelScript : public IScript
    {
    public:
        LevelScript(Level::Ptr InLevel);
        virtual ~LevelScript();

        virtual bool Execute(const String& InFilePath) override;

    private:
        Level::Ptr m_Level;
    };
}