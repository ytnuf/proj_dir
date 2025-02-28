
add_library("proj-dir-lib")
add_library("proj-dir::lib" ALIAS "proj-dir-lib")
target_sources("proj-dir-lib" PRIVATE
    "linux.cpp"
    "windows.cpp"
)

target_link_libraries("proj-dir-lib"
    PUBLIC "proj-dir::lib::inc"
)
