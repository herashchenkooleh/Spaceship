#pragma once

#include "ssg/PlayerController.hpp"
#include "ssg/IScript.hpp"

namespace ssg
{
    class PlayerControllerScript : public IScript
    {
    public:
        PlayerControllerScript(PlayerController::Ptr InPlayerContoller);
        virtual ~PlayerControllerScript();

        virtual bool Execute(const String& InFilePath) override;

    private:
        PlayerController::Ptr m_PlayerContoller;
    };
}