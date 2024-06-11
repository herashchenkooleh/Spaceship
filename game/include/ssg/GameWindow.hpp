#pragma once

#include "ssg/Global.hpp"
#include "ssg/InputEvent.hpp"

namespace ssg
{
    class GameWindow
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<GameWindow>;

        using RenderTargetHandle = void*;

    public:
        GameWindow();
        ~GameWindow();

        GameWindow(const GameWindow& InObj) = delete;
        GameWindow& operator=(const GameWindow& InObj) = delete;

        bool Create(const unsigned int InWidth, const unsigned int InHeight, const char* InTitle);

        InputEvent PollEvent();
        void Close();

        RenderTargetHandle GetRenderTarget() const;

        Vector2D GetSize() const;

    private:
        ImplementationPtr m_Implementation;
    };
}