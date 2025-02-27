
#include <filesystem>
#include <stdexcept>
#ifdef _WIN32

#include <dirs/windows.hpp>

#include <shlobj.h>
#include <winnt.h>

#include <memory>
#include <string>


namespace Dirs::Win
{


namespace
{


Fs::path getKnownFolder(REFKNOWNFOLDERID rfid, const std::string& name) {
    PWSTR path_raw_;
    const auto err = SHGetKnownFolderPath(rfid, 0, nullptr, &path_raw_);
    if(err == S_OK) {
        // As Fs::path's constructor can throw, let's first wrap the pointer in a unique_ptr to prevent any memory leak
        std::unique_ptr<WCHAR, decltype(&CoTaskMemFree)> path_{path_raw_, &CoTaskMemFree};
        return Fs::path{path_.get()};
    } else if(err == E_INVALIDARG) {
        throw std::runtime_error("SHGetKnownFolderPath: system doesn't contain KNOWNFOLDERID~" + name);
    } else if(err == E_FAIL) {
        throw std::runtime_error("SHGetKnownFolderPath: can't find path for KNOWNFOLDERID~" + name);
    } else {
        throw std::runtime_error("Miscellaneous error for SHGetKnownFolderPath: ~" + name);
    }
}


} // namespace


Fs::path accountPictures() {
    return getKnownFolder(FOLDERID_AccountPictures, "AccountPictures");
}


Fs::path adminTools() {
    return getKnownFolder(FOLDERID_AdminTools, "AdminTools");
}

Fs::path commonAdminTools() {
    return getKnownFolder(FOLDERID_CommonAdminTools, "CommonAdminTools");
}

Fs::path commonPrograms() {
    return getKnownFolder(FOLDERID_CommonPrograms, "CommonPrograms");
}

Fs::path commonStartMenu() {
    return getKnownFolder(FOLDERID_CommonStartMenu, "CommonStartMenu");
}

Fs::path commonTemplates() {
    return getKnownFolder(FOLDERID_CommonTemplates, "CommonTemplates");
}

Fs::path contacts() {
    return getKnownFolder(FOLDERID_Contacts, "Contacts");
}

Fs::path cookies() {
    return getKnownFolder(FOLDERID_Cookies, "Cookies");
}

Fs::path desktop() {
    return getKnownFolder(FOLDERID_Desktop, "Desktop");
}

Fs::path documents() {
    return getKnownFolder(FOLDERID_Documents, "Documents");
}

Fs::path downloads() {
    return getKnownFolder(FOLDERID_Downloads, "Downloads");
}

Fs::path favorites() {
    return getKnownFolder(FOLDERID_Favorites, "Favorites");
}

Fs::path fonts() {
    return getKnownFolder(FOLDERID_Fonts, "Fonts");
}

Fs::path history() {
    return getKnownFolder(FOLDERID_History, "History");
}

Fs::path internetCache() {
    return getKnownFolder(FOLDERID_InternetCache, "InternetCache");
}

Fs::path links() {
    return getKnownFolder(FOLDERID_Links, "Links");
}

Fs::path localAppData() {
    return getKnownFolder(FOLDERID_LocalAppData, "LocalAppData");
}

Fs::path localAppDataLow() {
    return getKnownFolder(FOLDERID_LocalAppDataLow, "LocalAppDataLow");
}

Fs::path music() {
    return getKnownFolder(FOLDERID_Music, "Music");
}

Fs::path netHood() {
    return getKnownFolder(FOLDERID_NetHood, "NetHood");
}


Fs::path pictures() {
    return getKnownFolder(FOLDERID_Pictures, "Pictures");
}

Fs::path printHood() {
    return getKnownFolder(FOLDERID_PrintHood, "PrintHood");
}

Fs::path profile() {
    return getKnownFolder(FOLDERID_Profile, "Profile");
}

Fs::path programData() {
    return getKnownFolder(FOLDERID_ProgramData, "ProgramData");
}

Fs::path programFiles() {
    return getKnownFolder(FOLDERID_ProgramFiles, "ProgramFiles");
}

Fs::path programFilesX64() {
    return getKnownFolder(FOLDERID_ProgramFilesX64, "ProgramFilesX64");
}

Fs::path programFilesX86() {
    return getKnownFolder(FOLDERID_ProgramFilesX86, "ProgramFilesX86");
}

Fs::path programFilesCommon() {
    return getKnownFolder(FOLDERID_ProgramFilesCommon, "ProgramFilesCommon");
}

Fs::path programFilesCommonX64() {
    return getKnownFolder(FOLDERID_ProgramFilesCommonX64, "ProgramFilesCommonX64");
}

Fs::path programFilesCommonX86() {
    return getKnownFolder(FOLDERID_ProgramFilesCommonX86, "ProgramFilesCommonX86");
}

Fs::path programs() {
    return getKnownFolder(FOLDERID_Programs, "Programs");
}

Fs::path publicBase() {
    return getKnownFolder(FOLDERID_Public, "PublicBase");
}

Fs::path publicDesktop() {
    return getKnownFolder(FOLDERID_PublicDesktop, "PublicDesktop");
}

Fs::path publicDocuments() {
    return getKnownFolder(FOLDERID_PublicDocuments, "PublicDocuments");
}

Fs::path publicMusic() {
    return getKnownFolder(FOLDERID_PublicMusic, "PublicMusic");
}

Fs::path publicPictures() {
    return getKnownFolder(FOLDERID_PublicPictures, "PublicPictures");
}

Fs::path publicVideos() {
    return getKnownFolder(FOLDERID_PublicVideos, "PublicVideos");
}

Fs::path recent() {
    return getKnownFolder(FOLDERID_Recent, "Recent");
}

Fs::path resourceDir() {
    return getKnownFolder(FOLDERID_ResourceDir, "ResourceDir");
}

Fs::path roamingAppData() {
    return getKnownFolder(FOLDERID_RoamingAppData, "RoamingAppData");
}

Fs::path savedGames() {
    return getKnownFolder(FOLDERID_SavedGames, "SavedGames");
}

Fs::path savedSearches() {
    return getKnownFolder(FOLDERID_SavedSearches, "SavedSearches");
}

Fs::path sendTo() {
    return getKnownFolder(FOLDERID_SendTo, "SendTo");
}

Fs::path startMenu() {
    return getKnownFolder(FOLDERID_StartMenu, "StartMenu");
}

Fs::path startup() {
    return getKnownFolder(FOLDERID_Startup, "Startup");
}

Fs::path system() {
    return getKnownFolder(FOLDERID_System, "System");
}

Fs::path systemX86() {
    return getKnownFolder(FOLDERID_SystemX86, "SystemX86");
}

Fs::path templates() {
    return getKnownFolder(FOLDERID_Templates, "Templates");
}

Fs::path userProfiles() {
    return getKnownFolder(FOLDERID_UserProfiles, "UserProfiles");
}

Fs::path videos() {
    return getKnownFolder(FOLDERID_Videos, "Videos");
}

Fs::path windows() {
    return getKnownFolder(FOLDERID_Windows, "Windows");
}


} // namespace Dirs::Win


#endif // ifdef _WIN32
