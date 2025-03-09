
#include <proj_dir/folders.hpp>

#include <proj_dir/linux.hpp>
#include <proj_dir/windows.hpp>

#include <filesystem>
#include <string_view>


namespace ProjDir
{


using std::filesystem::path, std::string_view;


namespace
{


path getRelDir(string_view projName, string_view orgName) {
    if(orgName.empty() )
        return projName;
    else
        return path(orgName) / projName;
}


} // namespace


path cacheDir(string_view projName, string_view orgName)
{
    const auto relDir = getRelDir(projName, orgName);
#ifdef __linux__
    return Linux::xdgCacheHome() / relDir;
#elif defined(_WIN32)
    return Win::localAppData() / "Temp" / relDir;
#else
    static_assert(false, "Unsupported OS");
#endif // #ifdef OS
}

path configDir(string_view projName, string_view orgName)
{
    const auto relDir = getRelDir(projName, orgName);
#ifdef __linux__
    return Linux::xdgConfigHome() / relDir;
#elif defined(_WIN32)
    return Win::roamingAppData() / relDir / "config_folder";
#else
    static_assert(false, "Unsupported OS");
#endif // #ifdef OS
}

path dataDir(string_view projName, string_view orgName)
{
    const auto relDir = getRelDir(projName, orgName);
#ifdef __linux__
    return Linux::xdgDataHome() / relDir;
#elif defined(_WIN32)
    return Win::roamingAppData() / relDir;
#else
    static_assert(false, "Unsupported OS");
#endif // #ifdef OS
}

path gameSaveDir(string_view projName, string_view orgName)
{
#ifdef _WIN32
    const auto relDir = getRelDir(projName, orgName);
    return Win::savedGames() / relDir;
#else
    return dataDir(projName, orgName) / "save_folder";
#endif // #ifdef OS
}

path stateDir(string_view projName, string_view orgName)
{
    const auto relDir = getRelDir(projName, orgName);
#ifdef __linux__
    return Linux::xdgStateHome() / relDir;
#elif defined(_WIN32)
    return Win::localAppData() / relDir;
#else
    static_assert(false, "Unsupported OS");
#endif // #ifdef OS
}


} // namespace ProjDir
