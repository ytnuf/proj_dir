
#include <filesystem>
#include <string_view>
#ifdef __linux__

#include <dirs/linux.hpp>

#include <cassert>
#include <cstdlib>


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


} // namespace Dirs::Linux


#endif // ifdef __linux__
