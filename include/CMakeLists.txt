
add_library("proj-dirs-headers" INTERFACE)
add_library("proj-dirs::headers" ALIAS "proj-dirs-headers")
target_sources("proj-dirs-headers" PUBLIC FILE_SET HEADERS FILES
    "dirs/linux.hpp"
)
