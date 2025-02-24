
#ifndef HPP_PROJDIRS_DIRS_LINUX_
#define HPP_PROJDIRS_DIRS_LINUX_

#ifdef __linux__

#include <filesystem>


/**
 * @brief Contains functions to get the XDG base directories
 * @see https://specifications.freedesktop.org/basedir-spec/latest/
 */
namespace Dirs::Linux
{


namespace Fs = std::filesystem;

/**
 * @brief Gets the folder for user-specific data files
 */
Fs::path xdgDataHome();


} // namespace Dirs::Linux


#endif // ifdef __linux__

#endif // ifndef HPP_PROJDIRS_DIRS_LINUX_
