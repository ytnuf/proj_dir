
add_library("proj-dirs-lib")
add_library("proj-dirs::lib" ALIAS "proj-dirs-lib")
target_sources("proj-dirs-lib" PRIVATE
    "linux.cpp"
)

target_link_libraries("proj-dirs-lib"
    PUBLIC "proj-dirs::headers"
)
