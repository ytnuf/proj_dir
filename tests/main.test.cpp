
#include <dirs/linux.hpp>
#include <dirs/windows.hpp>

#include <fmt/base.h>
#include <fmt/ranges.h>
#include <fmt/std.h>

int main() {
#ifdef __linux__
    using namespace Dirs::Linux;
    fmt::println("Linux directories: ");
    fmt::println("xdgCacheHome: {}", xdgCacheHome() );
    fmt::println("xdgConfigHome: {}", xdgConfigHome() );
    fmt::println("xdgDataHome: {}", xdgDataHome() );
    fmt::println("xdgStateHome: {}", xdgStateHome() );
    fmt::println("xdgConfigDirs:  {}", fmt::join(xdgConfigDirs(), "; ") );
    fmt::println("xdgDataDirs:  {}", fmt::join(xdgDataDirs(), "; ") );
#elif defined(_WIN32)
    using namespace Dirs::Win;
    fmt::print("roamingAppData: {}\n", roamingAppData() );
#endif // #ifdef OS

    return 0;
}
