
#ifndef HPP_PROJDIRS_DIRS_WINDOWS_
#define HPP_PROJDIRS_DIRS_WINDOWS_

#ifdef _WIN32

#include <filesystem>


namespace Dirs::Win
{


namespace Fs = std::filesystem;

Fs::path accountPictures();
Fs::path adminTools();

Fs::path commonAdminTools();
Fs::path commonPrograms();
Fs::path commonStartMenu();
Fs::path commonTemplates();
Fs::path contacts();
Fs::path cookies();

Fs::path desktop();
Fs::path documents();
Fs::path downloads();

Fs::path favorites();
Fs::path fonts();

Fs::path history();

Fs::path internetCache();

Fs::path links();
Fs::path localAppData();
Fs::path localAppDataLow();

Fs::path music();

Fs::path netHood();

Fs::path pictures();
Fs::path printHood();
Fs::path profile();
Fs::path programData();
Fs::path programFiles();
Fs::path programFilesX64();
Fs::path programFilesX86();
Fs::path programFilesCommon();
Fs::path programFilesCommonX64();
Fs::path programFilesCommonX86();
Fs::path programs();
Fs::path publicBase();
Fs::path publicDesktop();
Fs::path publicDocuments();
Fs::path publicMusic();
Fs::path publicPictures();
Fs::path publicVideos();

Fs::path recent();
Fs::path resourceDir();
Fs::path roamingAppData();

Fs::path savedGames();
Fs::path savedSearches();
Fs::path sendTo();
Fs::path startMenu();
Fs::path startup();
Fs::path system();
Fs::path systemX86();

Fs::path templates();

Fs::path userProfiles();

Fs::path videos();

Fs::path windows();


} // namespace Dirs::Win


#endif // ifdef _WIN32

#endif // ifndef HPP_PROJDIRS_DIRS_WINDOWS_
