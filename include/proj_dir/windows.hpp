
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


std::filesystem::path exeDir();

std::filesystem::path accountPictures();
std::filesystem::path adminTools();

std::filesystem::path commonAdminTools();
std::filesystem::path commonPrograms();
std::filesystem::path commonStartMenu();
std::filesystem::path commonTemplates();
std::filesystem::path contacts();
std::filesystem::path cookies();

std::filesystem::path desktop();
std::filesystem::path documents();
std::filesystem::path downloads();

std::filesystem::path favorites();
std::filesystem::path fonts();

std::filesystem::path history();

std::filesystem::path internetCache();

std::filesystem::path links();
std::filesystem::path localAppData();
std::filesystem::path localAppDataLow();

std::filesystem::path music();

std::filesystem::path netHood();

std::filesystem::path pictures();
std::filesystem::path printHood();
std::filesystem::path profile();
std::filesystem::path programData();
std::filesystem::path programFiles();
std::filesystem::path programFilesX64();
std::filesystem::path programFilesX86();
std::filesystem::path programFilesCommon();
std::filesystem::path programFilesCommonX64();
std::filesystem::path programFilesCommonX86();
std::filesystem::path programs();
std::filesystem::path publicBase();
std::filesystem::path publicDesktop();
std::filesystem::path publicDocuments();
std::filesystem::path publicMusic();
std::filesystem::path publicPictures();
std::filesystem::path publicVideos();

std::filesystem::path recent();
std::filesystem::path resourceDir();
std::filesystem::path roamingAppData();

std::filesystem::path savedGames();
std::filesystem::path savedSearches();
std::filesystem::path sendTo();
std::filesystem::path startMenu();
std::filesystem::path startup();
std::filesystem::path system();
std::filesystem::path systemX86();

std::filesystem::path templates();

std::filesystem::path userProfiles();

std::filesystem::path videos();

std::filesystem::path windows();


} // namespace ProjDir::Win


#endif // ifdef _WIN32

#endif // ifndef HPP_FUNTY_PROJDIR_WINDOWS_
