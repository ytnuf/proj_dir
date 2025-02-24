
#include <dirs/linux.hpp>

#include <iostream>


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
#endif // #ifdef __linux__

    return 0;
}
