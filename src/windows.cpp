
#include <filesystem>
#ifdef _WIN32

#include <dirs/windows.hpp>

#include <shlobj.h>
#include <winnt.h>

#include <memory>


namespace Dirs::Win
{


Fs::path roamingAppData() {
    PWSTR path_raw_;
    const auto res = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &path_raw_);
    // As Fs::path's constructor can throw, let's first wrap the pointer in a unique_ptr to prevent any memory leak
    std::unique_ptr<WCHAR, decltype(&CoTaskMemFree)> path_{path_raw_, &CoTaskMemFree};
    return Fs::path{path_.get()};
}


} // namespace Dirs::Win


#endif // ifdef _WIN32
