
#ifdef __linux__

#include <dirs/linux.hpp>

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <initializer_list>
#include <string_view>
#include <vector>


namespace Dirs::Linux
{


/*
 * Note that $HOME is required to be set, per the POSIX specification (#8.3)
 * HOME: The system shall initialize this variable at the time of login to be a pathname of the user's home directory.
 * https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/
 */
namespace
{


Fs::path getEnvHomeDir(std::string_view envKey, const Fs::path& relDir) {
    const char* envDir = std::getenv(envKey.data() );
    if(envDir) {
        return envDir;
    } else {
        const char* homeDir = std::getenv("HOME");
        assert(homeDir);
        return Fs::path(homeDir) / relDir;
    }
}

std::vector<Fs::path> getEnvSystemDirs(
        std::string_view envKey,
        std::initializer_list<Fs::path> defaultDirs
) {
    const char* dirLstBgn = std::getenv(envKey.data() );
    if(dirLstBgn) {
        const char* dirLstEnd = dirLstBgn + std::strlen(dirLstBgn);
        assert(!*dirLstEnd);
        std::vector<Fs::path> dataDirLst{};
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


Fs::path xdgCacheHome(){
    return getEnvHomeDir("XDG_CACHE_HOME", ".cache");
}

Fs::path xdgConfigHome(){
    return getEnvHomeDir("XDG_CONFIG_HOME", ".config");
}

Fs::path xdgDataHome() {
    return getEnvHomeDir("XDG_DATA_HOME", ".local/share");
}

Fs::path xdgStateHome(){
    return getEnvHomeDir("XDG_STATE_HOME", "/.local/state");
}

std::vector<Fs::path> xdgConfigDirs() {
    return getEnvSystemDirs("XDG_CONFIG_DIRS", {"/etc/xdg"});
}

std::vector<Fs::path> xdgDataDirs() {
    return getEnvSystemDirs("XDG_DATA_DIRS", {"/usr/local/share", "/usr/share"});
}


} // namespace Dirs::Linux


#endif // ifdef __linux__
