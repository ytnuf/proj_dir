
#ifndef HPP_FUNTY_PROJDIR_LINUX_
#define HPP_FUNTY_PROJDIR_LINUX_

#ifdef __linux__

#include <filesystem>
#include <vector>


/**
 * @brief Contains functions to get the XDG base directories
 * @see https://specifications.freedesktop.org/basedir-spec/latest/
 */
namespace ProjDir::Linux
{


/**
 * @brief The folder that contains the directory
 */
std::filesystem::path exeDir();

/**
 * @brief Get the folder for user-specific non-essential (cached) data
 */
std::filesystem::path xdgCacheHome();

/**
 * @brief Get the folder for user-specific configuration files
 */
std::filesystem::path xdgConfigHome();

/**
 * @brief Get the folder for user-specific data files
 */
std::filesystem::path xdgDataHome();

/**
 * @brief Get the folder for user-specific state data
 */
std::filesystem::path xdgStateHome();

/**
 * @brief Get the folder for user-specific runtime files
 */
std::filesystem::path xdgRuntimeDir();

/**
 * @brief Get a list of system folders for configuration files
 */
std::vector<std::filesystem::path> xdgConfigDirs();

/**
 * @brief Get a list of system folders for data files
 */
std::vector<std::filesystem::path> xdgDataDirs();


} // namespace ProjDir::Linux


#endif // ifdef __linux__

#endif // ifndef HPP_FUNTY_PROJDIR_LINUX_
