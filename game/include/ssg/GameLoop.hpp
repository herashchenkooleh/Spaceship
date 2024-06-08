#pragma once

#include "ssg/Global.hpp"

namespace ssg
{
    class GameLoop
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<GameLoop>;

    public:
        GameLoop();
        ~GameLoop();

        GameLoop(const GameLoop& InObj) = delete;
        GameLoop& operator=(const GameLoop& InObj) = delete;

        bool Initialize();
        void Start();
        void Deinitialize();

    private:
        ImplementationPtr m_Implementation;
    };
}