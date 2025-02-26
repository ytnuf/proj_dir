
add_executable("proj-dirs-exe")
target_sources("proj-dirs-exe" PRIVATE
    "main.test.cpp"
)

find_package("fmt" 11 CONFIG REQUIRED)

target_link_libraries("proj-dirs-exe"
    PRIVATE "fmt::fmt"
    PRIVATE "proj-dirs::lib"
)
