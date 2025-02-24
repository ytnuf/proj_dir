
#include <dirs/linux.hpp>

#include <iostream>


int main() {
#ifdef __linux__
    std::cout<<"Linux directories: "<<std::endl;
    std::cout<<Dirs::Linux::xdgDataHome()<<std::endl;
#endif // #ifdef __linux__

    return 0;
}
