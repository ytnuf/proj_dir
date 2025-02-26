
include_guard(GLOBAL)

# These variables should be set by presets
option(USE_CCACHE "Use ccache if found" OFF)
option(BUILD_TESTING "Build the testing tree" OFF)

# Note that CMAKE_<LANG>_COMPILER_LAUNCHER would need to set before the project() call
if(USE_CCACHE)
    find_program(CCACHE_PROGRAM ccache)
    if(CCACHE_PROGRAM)
        # Get version information
        execute_process(
            COMMAND "${CCACHE_PROGRAM}" "--version"
            OUTPUT_VARIABLE CCACHE_VERSION
        )
        string(REGEX MATCH "[^\r\n]*" CCACHE_VERSION "${CCACHE_VERSION}")

        message(STATUS "Using ccache: ${CCACHE_PROGRAM} (${CCACHE_VERSION})")

        # Turn on ccache for all targets
        set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
        set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
    else()
        message(WARNING "Unable to find ccache")
    endif()
endif()

if(BUILD_TESTING)
  list(APPEND VCPKG_MANIFEST_FEATURES "testing")
endif()
