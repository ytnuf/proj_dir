
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


Fs::path xdgDataHome() {
    const char* dataHomeDir = std::getenv("XDG_DATA_HOME");
    if(dataHomeDir) {
        return dataHomeDir;
    } else {
        const char* homeDir = std::getenv("HOME");
        assert(homeDir);
        return Fs::path(homeDir) / ".local" / "share";
    }
}


} // namespace Dirs::Linux


#endif // ifdef __linux__
