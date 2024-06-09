#include "ssg/Configs.hpp"

namespace ssg
{
	/*static*/ String Configs::s_GlobalRelBinaryPathSettingName = "global.relative_binary_path";
	/*static*/ String Configs::s_GlobalRelAssetsPathSettingName = "global.relative_assets_path";
	/*static*/ String Configs::s_GlobalDefaultMissionGameStateSettingName = "global.default_mission_file";
	/*static*/ String Configs::s_GlobalDefaultShellGameStateSettingName = "global.default_mission_file";

    struct Configs::Implementaion
	{
		UnorderedMap<String, Any> m_Settings;
	};

	Configs::Configs()
		: m_Implementation(MakeShared<Implementaion>())
	{

	}

    Configs::~Configs() = default;

    /*static*/ Configs& Configs::GetInstance()
    {
        static Configs s_Instance;

        return s_Instance;
    }

    template<typename Type>
	Type Configs::GetSetting(const String& Name) const
	{
		auto Iter = m_Implementation->m_Settings.find(Name);
		if (Iter != m_Implementation->m_Settings.end())
		{
			return AnyCast<Type>(Iter->second);
		}

		return Type();
	}

	template double Configs::GetSetting<double>(const String&) const;
	template void Configs::SetSetting<double>(const String&, double);

	template bool Configs::GetSetting<bool>(const String&) const;
	template void Configs::SetSetting<bool>(const String&, bool);

	template int Configs::GetSetting<int>(const String&) const;
	template void Configs::SetSetting<int>(const String&, int);

	template String Configs::GetSetting<String>(const String&) const;
	template void Configs::SetSetting<String>(const String&, String);

	template<typename Type>
	void Configs::SetSetting(const String& Name, Type Value)
	{
		auto Iter = m_Implementation->m_Settings.find(Name);
		if (Iter != m_Implementation->m_Settings.end())
		{
			Iter->second = Value;
		}
		else
		{
			m_Implementation->m_Settings.insert(std::make_pair(Name, Any(Value)));
		}
	}
}