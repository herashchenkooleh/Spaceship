#include "ssg/FileSystemHelper.hpp"

#include <filesystem>

namespace ssg
{
    /*static*/ String FileSystemHelper::GetLaunchDirectory()
    {
        return std::filesystem::current_path();
    }

    /*static*/ String FileSystemHelper::Join(const String& InLPath, const String& InRPath)
    {
        decltype(auto) Reuslt = std::filesystem::path(InLPath) / std::filesystem::path(InRPath);
        return Reuslt.string();
    }

    /*static*/ String FileSystemHelper::GetBasePath(const String& InPath)
    {
        return std::filesystem::path(InPath).remove_filename();
    }
}