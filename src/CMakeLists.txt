
add_library("proj-dir-lib")
add_library("proj-dir::lib" ALIAS "proj-dir-lib")
target_sources("proj-dir-lib" PRIVATE
    "folders.cpp"
    "linux.cpp"
    "windows.cpp"
)

target_compile_features("proj-dir-lib" PUBLIC "cxx_std_17")

target_link_libraries("proj-dir-lib"
    PUBLIC "proj-dir::lib::inc"
)

set_target_properties("proj-dir-lib" PROPERTIES
    EXPORT_NAME "lib"
)

include("GNUInstallDirs")
install(TARGETS "proj-dir-lib"
    EXPORT "proj-dir-config"
    RUNTIME
        DESTINATION "${CMAKE_INSTALL_BINDIR}"
        COMPONENT "funty-runtime"
    LIBRARY
        DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        COMPONENT "funty-dev"
        NAMELINK_COMPONENT "funty-runtime"
    ARCHIVE
        DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        COMPONENT "funty-dev"
)
