
#ifndef HPP_FUNTY_PROJDIR_FOLDERS_
#define HPP_FUNTY_PROJDIR_FOLDERS_


#include <filesystem>
#include <string_view>


namespace ProjDir
{


/**
 * @brief The folder for the project's user-specific state files
 * @param projName - A name for the project
 * @param orgName - A name for the organisation (can be empty)
 */
std::filesystem::path stateDir(std::string_view projName, std::string_view orgName = "");


} // namespace ProjDir


#endif // ifndef HPP_FUNTY_PROJDIR_FOLDERS_
