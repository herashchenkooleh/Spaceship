#pragma once

#include "ssg/Global.hpp"

namespace ssg
{
    class Objective
    {
    public:
        using Ptr = SharedPtr<Objective>;

        Objective();
        ~Objective();

        Objective(const Objective& InObj);
        Objective& operator=(const Objective& InObj);

        bool Initialize();
        void Update();

        static bool RegisterScriptType();

        const String& GetName() const { return m_Name; }

        void DynamicSet(const String& InKey, ScriptStackObject InValue);
	    ScriptObject DynamicGet(const String& InKey);

    private:
        String m_Name;
        ScriptFunction m_Function;

        UnorderedMap<String, ScriptObject> m_Entries;
    };
}