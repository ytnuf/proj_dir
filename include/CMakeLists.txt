
add_library("proj-dir-lib-inc" INTERFACE)
add_library("proj-dir::lib::inc" ALIAS "proj-dir-lib-inc")
target_sources("proj-dir-lib-inc" INTERFACE FILE_SET HEADERS FILES
    "proj_dir/folders.hpp"
    "proj_dir/linux.hpp"
    "proj_dir/windows.hpp"
)

target_compile_features("proj-dir-lib-inc" INTERFACE "cxx_std_17")

include("GNUInstallDirs")
install(TARGETS "proj-dir-lib-inc"
    EXPORT "proj-dir-config"
    FILE_SET HEADERS
    LIBRARY
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
        COMPONENT "funty-dev"
    ARCHIVE
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
        COMPONENT "funty-dev"
)
