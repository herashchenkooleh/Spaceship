#pragma once

#include "Configs.hpp"
#include "InputEvent.hpp"

namespace SpaceShipGame
{
    class GameWindow
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<GameWindow>;

    public:
        GameWindow();
        ~GameWindow();

        GameWindow(const GameWindow& InObj) = delete;
        GameWindow& operator=(const GameWindow& InObj) = delete;

        bool Create(const unsigned int InWidth, const unsigned int InHeight, const char* InTitle);

        InputEvent PollEvent();
        void Close();

    private:
        ImplementationPtr m_Implementation;
    };
}