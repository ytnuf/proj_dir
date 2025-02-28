
add_executable("proj-dir-exe")
target_sources("proj-dir-exe" PRIVATE
    "main.test.cpp"
)

find_package("fmt" 11 CONFIG REQUIRED)

target_link_libraries("proj-dir-exe"
    PRIVATE "fmt::fmt"
    PRIVATE "proj-dir::lib"
)
