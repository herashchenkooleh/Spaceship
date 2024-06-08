#pragma once

#include "ssg/Global.hpp"

namespace ssg
{
    class Configs
	{
		struct Implementaion;
		using ImplementaionPtr = SharedPtr<Implementaion>;

	public:
        static Configs& GetInstance();

        Configs(const Configs& InObj) = delete;
        Configs& operator=(const Configs& InObj) = delete;

		template<typename Type>
		Type GetSetting(const String& Name) const;

		template<typename Type>
		void SetSetting(const String& Name, Type Value);

	private:
        Configs();
		~Configs();

		ImplementaionPtr m_Implementation;
	};
}