#pragma once

#include "ssg/Global.hpp"

namespace ssg
{
    class FileSystemHelper
    {
    public:
        static String GetLaunchDirectory();

        static String Join(const String& InLPath, const String& InRPath);

        static String GetBasePath(const String& InPath);

        static String GetAssetFilePath(const String& InAsset);
    };
}