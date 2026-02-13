# Create static library
add_library(ipb_arithmetic STATIC
    sum.cpp
    subtract.cpp
)

# Public include directory
target_include_directories(ipb_arithmetic
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# Create executable
add_executable(test_ipb_arithmetic
    main.cpp
)

# Link executable to library
target_link_libraries(test_ipb_arithmetic
    PRIVATE ipb_arithmetic
)

# Install executable (optional but clean)
install(TARGETS test_ipb_arithmetic
        RUNTIME DESTINATION bin)