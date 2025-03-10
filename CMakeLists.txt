
cmake_minimum_required(VERSION 3.29)

include("cmake/pre_project.cmake")

project("proj-dir"
    LANGUAGES "CXX"
)

include("cmake/options.cmake")

add_subdirectory("include/")
add_subdirectory("src/")

include("CTest")
if(BUILD_TESTING)
    add_subdirectory("tests/")
endif()

if(FUNTY_BUILD_DOCS)
    add_subdirectory("docs/")
endif()

install(EXPORT "proj-dir-config"
    NAMESPACE "proj-dir::"
    DESTINATION "${PROJDIR_CMAKEDIR}"
    COMPONENT "funty-dev"
)
include("GNUInstallDirs")
install(FILES "LICENSE.txt"
    DESTINATION "${CMAKE_INSTALL_DATADIR}/licenses/proj-dir"
)

# Prevents false-positive warning
block()
    set(UNUSED_VAR_ ${CMAKE_C_COMPILER})
    set(UNUSED_VAR_ ${UNUSED_VAR_})
endblock()
