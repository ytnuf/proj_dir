

#ifdef _WIN32

#include <proj_dir/windows.hpp>

#include <shlobj.h>
#include <winnt.h>

#include <filesystem>
#include <memory>
#include <stdexcept>
#include <string>


namespace ProjDir::Win
{


using std::filesystem::path;


namespace
{


path getKnownFolder(REFKNOWNFOLDERID rfid, const std::string& name) {
    PWSTR path_raw_;
    const auto err = SHGetKnownFolderPath(rfid, 0, nullptr, &path_raw_);
    if(err == S_OK) {
        // As path's constructor can throw, let's first wrap the pointer in a unique_ptr to prevent any memory leak
        std::unique_ptr<WCHAR, decltype(&CoTaskMemFree)> path_{path_raw_, &CoTaskMemFree};
        return path{path_.get()};
    } else if(err == E_INVALIDARG) {
        throw std::runtime_error("SHGetKnownFolderPath: system doesn't contain KNOWNFOLDERID~" + name);
    } else if(err == E_FAIL) {
        throw std::runtime_error("SHGetKnownFolderPath: can't find path for KNOWNFOLDERID~" + name);
    } else {
        throw std::runtime_error("Miscellaneous error for SHGetKnownFolderPath: ~" + name);
    }
}


} // namespace


path accountPictures() {
    return getKnownFolder(FOLDERID_AccountPictures, "AccountPictures");
}


path adminTools() {
    return getKnownFolder(FOLDERID_AdminTools, "AdminTools");
}

path commonAdminTools() {
    return getKnownFolder(FOLDERID_CommonAdminTools, "CommonAdminTools");
}

path commonPrograms() {
    return getKnownFolder(FOLDERID_CommonPrograms, "CommonPrograms");
}

path commonStartMenu() {
    return getKnownFolder(FOLDERID_CommonStartMenu, "CommonStartMenu");
}

path commonTemplates() {
    return getKnownFolder(FOLDERID_CommonTemplates, "CommonTemplates");
}

path contacts() {
    return getKnownFolder(FOLDERID_Contacts, "Contacts");
}

path cookies() {
    return getKnownFolder(FOLDERID_Cookies, "Cookies");
}

path desktop() {
    return getKnownFolder(FOLDERID_Desktop, "Desktop");
}

path documents() {
    return getKnownFolder(FOLDERID_Documents, "Documents");
}

path downloads() {
    return getKnownFolder(FOLDERID_Downloads, "Downloads");
}

path favorites() {
    return getKnownFolder(FOLDERID_Favorites, "Favorites");
}

path fonts() {
    return getKnownFolder(FOLDERID_Fonts, "Fonts");
}

path history() {
    return getKnownFolder(FOLDERID_History, "History");
}

path internetCache() {
    return getKnownFolder(FOLDERID_InternetCache, "InternetCache");
}

path links() {
    return getKnownFolder(FOLDERID_Links, "Links");
}

path localAppData() {
    return getKnownFolder(FOLDERID_LocalAppData, "LocalAppData");
}

path localAppDataLow() {
    return getKnownFolder(FOLDERID_LocalAppDataLow, "LocalAppDataLow");
}

path music() {
    return getKnownFolder(FOLDERID_Music, "Music");
}

path netHood() {
    return getKnownFolder(FOLDERID_NetHood, "NetHood");
}


path pictures() {
    return getKnownFolder(FOLDERID_Pictures, "Pictures");
}

path printHood() {
    return getKnownFolder(FOLDERID_PrintHood, "PrintHood");
}

path profile() {
    return getKnownFolder(FOLDERID_Profile, "Profile");
}

path programData() {
    return getKnownFolder(FOLDERID_ProgramData, "ProgramData");
}

path programFiles() {
    return getKnownFolder(FOLDERID_ProgramFiles, "ProgramFiles");
}

path programFilesX64() {
    return getKnownFolder(FOLDERID_ProgramFilesX64, "ProgramFilesX64");
}

path programFilesX86() {
    return getKnownFolder(FOLDERID_ProgramFilesX86, "ProgramFilesX86");
}

path programFilesCommon() {
    return getKnownFolder(FOLDERID_ProgramFilesCommon, "ProgramFilesCommon");
}

path programFilesCommonX64() {
    return getKnownFolder(FOLDERID_ProgramFilesCommonX64, "ProgramFilesCommonX64");
}

path programFilesCommonX86() {
    return getKnownFolder(FOLDERID_ProgramFilesCommonX86, "ProgramFilesCommonX86");
}

path programs() {
    return getKnownFolder(FOLDERID_Programs, "Programs");
}

path publicBase() {
    return getKnownFolder(FOLDERID_Public, "PublicBase");
}

path publicDesktop() {
    return getKnownFolder(FOLDERID_PublicDesktop, "PublicDesktop");
}

path publicDocuments() {
    return getKnownFolder(FOLDERID_PublicDocuments, "PublicDocuments");
}

path publicMusic() {
    return getKnownFolder(FOLDERID_PublicMusic, "PublicMusic");
}

path publicPictures() {
    return getKnownFolder(FOLDERID_PublicPictures, "PublicPictures");
}

path publicVideos() {
    return getKnownFolder(FOLDERID_PublicVideos, "PublicVideos");
}

path recent() {
    return getKnownFolder(FOLDERID_Recent, "Recent");
}

path resourceDir() {
    return getKnownFolder(FOLDERID_ResourceDir, "ResourceDir");
}

path roamingAppData() {
    return getKnownFolder(FOLDERID_RoamingAppData, "RoamingAppData");
}

path savedGames() {
    return getKnownFolder(FOLDERID_SavedGames, "SavedGames");
}

path savedSearches() {
    return getKnownFolder(FOLDERID_SavedSearches, "SavedSearches");
}

path sendTo() {
    return getKnownFolder(FOLDERID_SendTo, "SendTo");
}

path startMenu() {
    return getKnownFolder(FOLDERID_StartMenu, "StartMenu");
}

path startup() {
    return getKnownFolder(FOLDERID_Startup, "Startup");
}

path system() {
    return getKnownFolder(FOLDERID_System, "System");
}

path systemX86() {
    return getKnownFolder(FOLDERID_SystemX86, "SystemX86");
}

path templates() {
    return getKnownFolder(FOLDERID_Templates, "Templates");
}

path userProfiles() {
    return getKnownFolder(FOLDERID_UserProfiles, "UserProfiles");
}

path videos() {
    return getKnownFolder(FOLDERID_Videos, "Videos");
}

path windows() {
    return getKnownFolder(FOLDERID_Windows, "Windows");
}


} // namespace ProjDir::Win


#endif // ifdef _WIN32
