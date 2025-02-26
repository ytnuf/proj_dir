
#include <dirs/linux.hpp>
#include <dirs/windows.hpp>

#ifdef _WIN32
    #include <cstdio>
    #include <fcntl.h>
    #include <io.h>
#else
    #include <iostream>
#endif // ifdef _WIN32




int main() {
#ifdef __linux__
    std::cout<<"Linux directories: "<<std::endl;
    std::cout<<"xdgCacheHome: "<<Dirs::Linux::xdgCacheHome()<<std::endl;
    std::cout<<"xdgConfigHome: "<<Dirs::Linux::xdgConfigHome()<<std::endl;
    std::cout<<"xdgDataHome: "<<Dirs::Linux::xdgDataHome()<<std::endl;
    std::cout<<"xdgStateHome: "<<Dirs::Linux::xdgStateHome()<<std::endl;
    std::cout<<"xdgConfigDirs:   ";
    for(const auto& dir : Dirs::Linux::xdgConfigDirs() )
        std::cout<<dir<<"; ";
    std::cout<<std::endl;
    std::cout<<"xdgDataDirs:   ";
    for(const auto& dir : Dirs::Linux::xdgDataDirs() )
        std::cout<<dir<<"; ";
    std::cout<<std::endl;
#elif defined(_WIN32)
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wprintf(L"Windows directories: \n");
    std::wprintf(L"%S\n", Dirs::Win::roamingAppData().c_str() );
#endif // #ifdef OS

    return 0;
}
