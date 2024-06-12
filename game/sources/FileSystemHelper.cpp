#include "ssg/FileSystemHelper.hpp"
#include "ssg/Configs.hpp"
#include <filesystem>

namespace ssg
{
    /*static*/ String FileSystemHelper::GetLaunchDirectory()
    {
        return std::filesystem::current_path().string();
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

    /*static*/ String FileSystemHelper::GetAssetFilePath(const String& InAsset)
    {
        String RelAssetsPath = Configs::GetInstance().GetSetting<String>(Configs::s_GlobalRelAssetsPathSettingName);
        String RelBinaryPath = Configs::GetInstance().GetSetting<String>(Configs::s_GlobalRelBinaryPathSettingName);

        decltype(auto) FullBinaryPath = FileSystemHelper::Join(ssg::FileSystemHelper::GetLaunchDirectory(), RelBinaryPath);
        decltype(auto) BinaryPath = FileSystemHelper::GetBasePath(FullBinaryPath);
        decltype(auto) AssetsFolder = FileSystemHelper::Join(BinaryPath, RelAssetsPath);

        return FileSystemHelper::Join(AssetsFolder, InAsset);
    }
}