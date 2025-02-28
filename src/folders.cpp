
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


path stateDir(string_view projName, string_view orgName) {
    const auto relDir = getRelDir(projName, orgName);
#ifdef __linux__
    const auto stateBase = Linux::xdgStateHome();
    return stateBase / relDir;
#elif defined(_WIN32)
    const auto stateBase = Win::localAppData();
    return stateBase / relDir;
#else
    static_assert(false, "Unsupported OS");
#endif // #ifdef OS
}


} // namespace ProjDir
