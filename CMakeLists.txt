
cmake_minimum_required(VERSION 3.29)

include("cmake/pre_project.cmake")

project("proj_dirs"
    LANGUAGES "CXX"
)

include("cmake/options.cmake")

add_subdirectory("include/")
add_subdirectory("src/")

include("CTest")
if(BUILD_TESTING)
    add_subdirectory("tests/")
endif()

# Prevents false-positive warning
block()
    set(UNUSED_VAR_ ${CMAKE_C_COMPILER})
    set(UNUSED_VAR_ ${UNUSED_VAR_})
endblock()
