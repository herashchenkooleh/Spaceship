#pragma once

#include "ssg/Global.hpp"

namespace ssg
{
    class ScriptManager
    {
        struct Implementation;
        using ImplementationPtr = SharedPtr<Implementation>;

    public:
        using Ptr = SharedPtr<ScriptManager>;
        using ScriptContentHandle = void*;

        ScriptManager();
        ~ScriptManager();

        bool Initialize();

        ScriptContentHandle GetScriptContent();
        
    private:
        ImplementationPtr m_Implementation;
    };
}