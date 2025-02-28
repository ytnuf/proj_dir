
add_library("proj-dir-lib-inc" INTERFACE)
add_library("proj-dir::lib::inc" ALIAS "proj-dir-lib-inc")
target_sources("proj-dir-lib-inc" INTERFACE FILE_SET HEADERS FILES
    "proj_dir/folders.hpp"
    "proj_dir/linux.hpp"
    "proj_dir/windows.hpp"
)
