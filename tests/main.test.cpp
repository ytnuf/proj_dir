
#include <proj_dir/folders.hpp>
#include <proj_dir/linux.hpp>
#include <proj_dir/windows.hpp>

#include <fmt/base.h>
#include <fmt/ranges.h>
#include <fmt/std.h>

int main() {
    using namespace ProjDir;
    fmt::println("Project Directories: ");
    fmt::println("cacheDir: {}", cacheDir("proj_dir", "funty") );
    fmt::println("configDir: {}", configDir("proj_dir", "funty") );
    fmt::println("dataDir: {}", dataDir("proj_dir", "funty") );
    fmt::println("gameSaveDir: {}", gameSaveDir("proj_dir", "funty") );
    fmt::println("stateDir: {}", stateDir("proj_dir", "funty") );
    fmt::println("");
    #ifdef __linux__
    using namespace ProjDir::Linux;
    fmt::println("Linux directories: ");
    fmt::println("xdgCacheHome: {}", xdgCacheHome() );
    fmt::println("xdgConfigHome: {}", xdgConfigHome() );
    fmt::println("xdgDataHome: {}", xdgDataHome() );
    fmt::println("xdgStateHome: {}", xdgStateHome() );
    fmt::println("xdgConfigDirs:  {}", fmt::join(xdgConfigDirs(), "; ") );
    fmt::println("xdgDataDirs:  {}", fmt::join(xdgDataDirs(), "; ") );
#elif defined(_WIN32)
    using namespace ProjDir::Win;
    fmt::println("Windows directories: ");
    fmt::println("roamingAppData: {}", roamingAppData() );
    fmt::println("adminTools: {}", adminTools() );
    fmt::println("commonAdminTools: {}", commonAdminTools() );
    fmt::println("commonPrograms: {}", commonPrograms() );
    fmt::println("commonStartMenu: {}", commonStartMenu() );
    fmt::println("commonTemplates: {}", commonTemplates() );
    fmt::println("contacts: {}", contacts() );
    fmt::println("cookies: {}", cookies() );
    fmt::println("desktop: {}", desktop() );
    fmt::println("documents: {}", documents() );
    fmt::println("downloads: {}", downloads() );
    fmt::println("favorites: {}", favorites() );
    fmt::println("fonts: {}", fonts() );
    fmt::println("history: {}", history() );
    fmt::println("internetCache: {}", internetCache() );
    fmt::println("links: {}", links() );
    fmt::println("localAppData: {}", localAppData() );
    fmt::println("localAppDataLow: {}", localAppDataLow() );
    fmt::println("music: {}", music() );
    fmt::println("netHood: {}", netHood() );
    fmt::println("pictures: {}", pictures() );
    fmt::println("printHood: {}", printHood() );
    fmt::println("profile: {}", profile() );
    fmt::println("programData: {}", programData() );
    fmt::println("programFiles: {}", programFiles() );
    fmt::println("programFilesX64: {}", programFilesX64() );
    fmt::println("programFilesX86: {}", programFilesX86() );
    fmt::println("programFilesCommon: {}", programFilesCommon() );
    fmt::println("programFilesCommonX64: {}", programFilesCommonX64() );
    fmt::println("programFilesCommonX86: {}", programFilesCommonX86() );
    fmt::println("programs: {}", programs() );
    fmt::println("publicBase: {}", publicBase() );
    fmt::println("publicDesktop: {}", publicDesktop() );
    fmt::println("publicDocuments: {}", publicDocuments() );
    fmt::println("publicMusic: {}", publicMusic() );
    fmt::println("publicPictures: {}", publicPictures() );
    fmt::println("publicVideos: {}", publicVideos() );
    fmt::println("recent: {}", recent() );
    fmt::println("resourceDir: {}", resourceDir() );
    fmt::println("roamingAppData: {}", roamingAppData() );
    fmt::println("savedGames: {}", savedGames() );
    fmt::println("savedSearches: {}", savedSearches() );
    fmt::println("sendTo: {}", sendTo() );
    fmt::println("startMenu: {}", startMenu() );
    fmt::println("startup: {}", startup() );
    fmt::println("system: {}", system() );
    fmt::println("systemX86: {}", systemX86() );
    fmt::println("templates: {}", templates() );
    fmt::println("userProfiles: {}", userProfiles() );
    fmt::println("videos: {}", videos() );
    fmt::println("windows: {}", windows() );
#endif // #ifdef OS

    return 0;
}
