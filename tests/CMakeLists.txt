
add_executable("proj-dirs-exe")
target_sources("proj-dirs-exe" PRIVATE
    "main.test.cpp"
)

target_link_libraries("proj-dirs-exe"
    PRIVATE "proj-dirs::lib"
)
