#pragma once

#include "ssg/MissionGameState.hpp"
#include "ssg/IScript.hpp"

namespace ssg
{
    class MissionGameStateScript : public IScript
    {
    public:
        MissionGameStateScript(MissionGameState::Ptr InMissionState);
        virtual ~MissionGameStateScript();

        virtual bool Execute(const String& InFilePath) override;

    private:
        MissionGameState::Ptr m_Mission;
    };
}