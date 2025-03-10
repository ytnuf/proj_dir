
find_package("Doxygen" MODULE REQUIRED)

block()
    set(DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/doxygen")
    doxygen_add_docs("proj-dir-docs"
        "include/"
        ALL
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
        COMMENT "Generate HTML documentation"
    )
    include("GNUInstallDirs")
    install(DIRECTORY "${DOXYGEN_OUTPUT_DIRECTORY}/"
        DESTINATION "${CMAKE_INSTALL_DOCDIR}"
        COMPONENT "funty-dev"
    )
endblock()
