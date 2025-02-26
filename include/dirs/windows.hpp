
#ifndef HPP_PROJDIRS_DIRS_WINDOWS_
#define HPP_PROJDIRS_DIRS_WINDOWS_

#ifdef _WIN32

#include <filesystem>


namespace Dirs::Win
{


namespace Fs = std::filesystem;

Fs::path roamingAppData();


} // namespace Dirs::Win


#endif // ifdef _WIN32

#endif // ifndef HPP_PROJDIRS_DIRS_WINDOWS_
