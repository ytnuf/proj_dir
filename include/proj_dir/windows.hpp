
#ifndef HPP_FUNTY_PROJDIR_WINDOWS_
#define HPP_FUNTY_PROJDIR_WINDOWS_

#ifdef _WIN32

#include <filesystem>


/**
 * @brief Contains functions to get the Known Folders
 * @see https://learn.microsoft.com/en-us/windows/win32/shell/known-folders
 */
namespace ProjDir::Win
{


/**
 * @brief The folder that contains the executable
 */
std::filesystem::path exeDir();

/**
 *@brief The folder for the account pictures
 */
std::filesystem::path accountPictures();

/**
 *@brief The folder for the admin tools
 */
std::filesystem::path adminTools();

/**
 *@brief The folder for the common admin tools
 */
std::filesystem::path commonAdminTools();

/**
 *@brief The folder for the common programs
 */
std::filesystem::path commonPrograms();

/**
 *@brief The folder for the common start menu
 */
std::filesystem::path commonStartMenu();

/**
 *@brief The folder for the common templates
 */
std::filesystem::path commonTemplates();

/**
 *@brief The folder for the contacts
 */
std::filesystem::path contacts();

/**
 *@brief The folder for the cookies
 */
std::filesystem::path cookies();

/**
 *@brief The user's Desktop folder
 */
std::filesystem::path desktop();

/**
 *@brief The user's Documents folder
 */
std::filesystem::path documents();

/**
 *@brief The user's Downloads folder
 */
std::filesystem::path downloads();

/**
 *@brief The Favourites folder
 */
std::filesystem::path favorites();

/**
 *@brief The Fonts folder
 */
std::filesystem::path fonts();

/**
 *@brief The History folder
 */
std::filesystem::path history();

/**
 *@brief The folder for the internet cache
 */
std::filesystem::path internetCache();

/**
 *@brief The folder for the links
 */
std::filesystem::path links();

/**
 *@brief The folder for the user's local app data
 */
std::filesystem::path localAppData();

/**
 *@brief The folder for the user's local app data (lower integrity level)
 */
std::filesystem::path localAppDataLow();

/**
 *@brief The user's Music folder
 */
std::filesystem::path music();

/**
 *@brief The folder for Network Shortcuts
 */
std::filesystem::path netHood();

/**
 *@brief The user's Pictures folder
 */
std::filesystem::path pictures();

/**
 *@brief The folder for Printer Shortcuts
 */
std::filesystem::path printHood();

/**
 *@brief The user's home folder
 */
std::filesystem::path profile();

/**
 *@brief The folder for the program data
 */
std::filesystem::path programData();

/**
 *@brief The folder for the program files
 */
std::filesystem::path programFiles();

/**
 *@brief The folder for the program files x64
 */
std::filesystem::path programFilesX64();

/**
 *@brief The folder for the program files x86
 */
std::filesystem::path programFilesX86();

/**
 *@brief The folder for the program files commons
 */
std::filesystem::path programFilesCommon();

/**
 *@brief The folder for the program files commons x64
 */
std::filesystem::path programFilesCommonX64();

/**
 *@brief The folder for the program files commons x86
 */
std::filesystem::path programFilesCommonX86();

/**
 *@brief The folder for the start menu programs
 */
std::filesystem::path programs();

/**
 *@brief The public user folder
 */
std::filesystem::path publicBase();

/**
 *@brief The public desktop folder
 */
std::filesystem::path publicDesktop();

/**
 *@brief The public document folder
 */
std::filesystem::path publicDocuments();

/**
 *@brief The public music folder
 */
std::filesystem::path publicMusic();

/**
 *@brief The public pictures folder
 */
std::filesystem::path publicPictures();

/**
 *@brief The public videos folder
 */
std::filesystem::path publicVideos();

/**
 *@brief The folder for recent items
 */
std::filesystem::path recent();

/**
 *@brief The folder for system resources
 */
std::filesystem::path resourceDir();

/**
 *@brief The folder for the user's roaming app data
 */
std::filesystem::path roamingAppData();

/**
 *@brief The folder for saved games data
 */
std::filesystem::path savedGames();

/**
 *@brief The folder for saved searches
 */
std::filesystem::path savedSearches();

/**
 *@brief The sendTo folder
 */
std::filesystem::path sendTo();

/**
 *@brief The folder for the start-menu shortcuts
 */
std::filesystem::path startMenu();

/**
 *@brief The folder for the start-menu programs that startup
 */
std::filesystem::path startup();

/**
 *@brief The system32 folder
 */
std::filesystem::path system();

/**
 *@brief The folder for the system's 32-bit components
 */
std::filesystem::path systemX86();

/**
 *@brief The folder for templates
 */
std::filesystem::path templates();

/**
 *@brief The parent folder of the user folder
 */
std::filesystem::path userProfiles();

/**
 *@brief The user's videos folder
 */
std::filesystem::path videos();

/**
 *@brief The window folder
 */
std::filesystem::path windows();


} // namespace ProjDir::Win


#endif // ifdef _WIN32

#endif // ifndef HPP_FUNTY_PROJDIR_WINDOWS_
