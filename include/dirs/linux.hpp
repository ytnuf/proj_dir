
#ifndef HPP_PROJDIRS_DIRS_LINUX_
#define HPP_PROJDIRS_DIRS_LINUX_

#ifdef __linux__

#include <filesystem>
#include <vector>


/**
 * @brief Contains functions to get the XDG base directories
 * @see https://specifications.freedesktop.org/basedir-spec/latest/
 */
namespace Dirs::Linux
{


namespace Fs = std::filesystem;

/**
 * @brief Get the folder for user-specific non-essential (cached) data
 */
Fs::path xdgCacheHome();

/**
 * @brief Get the folder for user-specific configuration files
 */
Fs::path xdgConfigHome();

/**
 * @brief Get the folder for user-specific data files
 */
Fs::path xdgDataHome();

/**
 * @brief Get the folder for  user-specific state data
 */
Fs::path xdgStateHome();

/**
 * @brief Get a list of system folders for configuration files
 */
std::vector<Fs::path> xdgConfigDirs();

/**
 * @brief Get a list of system folders for data files
 */
std::vector<Fs::path> xdgDataDirs();


} // namespace Dirs::Linux


#endif // ifdef __linux__

#endif // ifndef HPP_PROJDIRS_DIRS_LINUX_
