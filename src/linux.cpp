
#ifdef __linux__

#include <proj_dir/linux.hpp>

#include <unistd.h>

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>


namespace ProjDir::Linux
{


using std::filesystem::path, std::string_literals::operator""s;


/*
 * Note that $HOME is required to be set, per the POSIX specification
 * HOME: The system shall initialize this variable at the time of login to be a pathname of the user's home directory.
 * https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/ (chapter #8.3)
 */
namespace
{


path getEnvHomeDir(std::string_view envKey, const path& relDir) {
    const char* envDir = std::getenv(envKey.data() );
    if(envDir) {
        return envDir;
    } else {
        const char* homeDir = std::getenv("HOME");
        assert(homeDir);
        return path(homeDir) / relDir;
    }
}

std::vector<path> getEnvSystemDirs(
        std::string_view envKey,
        std::initializer_list<path> defaultDirs
) {
    const char* dirLstBgn = std::getenv(envKey.data() );
    if(dirLstBgn) {
        const char* dirLstEnd = dirLstBgn + std::strlen(dirLstBgn);
        assert(!*dirLstEnd);
        std::vector<path> dataDirLst{};
        while(dirLstBgn < dirLstEnd) {
            const auto sepIter = std::find(dirLstBgn, dirLstEnd, ':');
            dataDirLst.emplace_back(dirLstBgn, sepIter);
            dirLstBgn = sepIter + 1;
        }
        return dataDirLst;
    } else {
        return defaultDirs;
    }
}


} // namespace


path exeDir() {
    using std::filesystem::canonical;
    try {
        return canonical("/proc/self/exe").parent_path();
    } catch(std::filesystem::filesystem_error& ex) {
        std::cerr<<ex.what()<<std::endl;
        return canonical("/proc/"s + std::to_string(getpid() ) + "/exe"s).parent_path();
    }
}


path xdgCacheHome(){
    return getEnvHomeDir("XDG_CACHE_HOME", ".cache");
}

path xdgConfigHome(){
    return getEnvHomeDir("XDG_CONFIG_HOME", ".config");
}

path xdgDataHome() {
    return getEnvHomeDir("XDG_DATA_HOME", ".local/share");
}

path xdgStateHome(){
    return getEnvHomeDir("XDG_STATE_HOME", "/.local/state");
}

path xdgRuntimeDir() {
    if(const char* runtimeDir = std::getenv("XDG_RUNTIME_DIR") )
        return runtimeDir;
    std::cerr<<"Error cannot obtain $XDG_RUNTIME_DIR, using a fallback!"<<std::endl;

    if(const char* userId = std::getenv("UID") )
        throw std::runtime_error("No $UID for a suitable runtime folder");
    else if(auto runDir = path("/run/user") / userId; std::filesystem::exists(runDir) )
        return runDir;
    else if(auto varRunDir = path("/var/run/user") / userId; std::filesystem::exists(varRunDir) )
        return varRunDir;
    else
        throw std::runtime_error("Unable to find a suitable runtime folder, all fallbacks failed");
}

std::vector<path> xdgConfigDirs() {
    return getEnvSystemDirs("XDG_CONFIG_DIRS", {"/etc/xdg"});
}

std::vector<path> xdgDataDirs() {
    return getEnvSystemDirs("XDG_DATA_DIRS", {"/usr/local/share", "/usr/share"});
}


} // namespace ProjDir::Linux


#endif // ifdef __linux__
