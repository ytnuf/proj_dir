
#include <dirs/linux.hpp>

#include <iostream>


int main() {
#ifdef __linux__
    std::cout<<"Linux directories: "<<std::endl;
    std::cout<<"xdgCacheHome: "<<Dirs::Linux::xdgCacheHome()<<std::endl;
    std::cout<<"xdgConfigHome: "<<Dirs::Linux::xdgConfigHome()<<std::endl;
    std::cout<<"xdgDataHome: "<<Dirs::Linux::xdgDataHome()<<std::endl;
    std::cout<<"xdgStateHome: "<<Dirs::Linux::xdgStateHome()<<std::endl;
#endif // #ifdef __linux__

    return 0;
}
