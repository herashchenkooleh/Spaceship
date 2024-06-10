#pragma once

#include "ssg/ShellGameState.hpp"
#include "ssg/IScript.hpp"

namespace ssg
{
    class ShellGameStateScript : public IScript
    {
    public:
        ShellGameStateScript(ShellGameState::Ptr InShellState);
        virtual ~ShellGameStateScript();

        virtual bool Execute(const String& InFilePath) override;

    private:
        ShellGameState::Ptr m_ShellState;
    };
}