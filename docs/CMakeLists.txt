
find_package("Doxygen" MODULE REQUIRED)

doxygen_add_docs("proj-dir-docs"
    "include/"
    ALL
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    COMMENT "Generate HTML documentation"
)
