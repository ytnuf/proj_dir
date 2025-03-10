
#ifndef HPP_FUNTY_PROJDIR_FOLDERS_
#define HPP_FUNTY_PROJDIR_FOLDERS_


#include <filesystem>
#include <string_view>


/**
 * @brief Contains functions to get various directables to be used by applications
 */
namespace ProjDir
{


/**
 * @brief The folder that contains the directory
 */
std::filesystem::path exeDir();

/**
 * @brief The folder for the project's user-specific cache files
 * @param projName - A name for the project
 * @param orgName - A name for the organisation (can be empty)
 */
std::filesystem::path cacheDir(std::string_view projName, std::string_view orgName = "");

/**
 * @brief The folder for the project's user-specific config files
 * @param projName - A name for the project
 * @param orgName - A name for the organisation (can be empty)
 */
std::filesystem::path configDir(std::string_view projName, std::string_view orgName = "");

/**
 * @brief The folder for the project's user-specific data files
 * @param projName - A name for the project
 * @param orgName - A name for the organisation (can be empty)
 */
std::filesystem::path dataDir(std::string_view projName, std::string_view orgName = "");

/**
 * @brief The folder for the project's save data
 * @param projName - A name for the project
 * @param orgName - A name for the organisation (can be empty)
 */
std::filesystem::path gameSaveDir(std::string_view projName, std::string_view orgName = "");

/**
 * @brief The folder for the project's user-specific state files
 * @param projName - A name for the project
 * @param orgName - A name for the organisation (can be empty)
 */
std::filesystem::path stateDir(std::string_view projName, std::string_view orgName = "");


} // namespace ProjDir


#endif // ifndef HPP_FUNTY_PROJDIR_FOLDERS_
