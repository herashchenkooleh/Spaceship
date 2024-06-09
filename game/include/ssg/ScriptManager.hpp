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

        const String& GetDefaultContentName() const { return s_DefaultContentName; }

        bool AddNewScriptContent(const String& InContentName);
        ScriptContentHandle GetScriptContent(const String& InContentName = s_DefaultContentName);
        void DeleteScriptContent(const String& InContentName);
        
    private:
        ImplementationPtr m_Implementation;

        static String s_DefaultContentName;
    };
}