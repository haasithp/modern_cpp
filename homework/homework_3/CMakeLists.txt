cmake_minimum_required(VERSION 3.10)
project(ImageBrowser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt REQUIRED)

# html_writer library
add_library(html_writer
    solutions/src/html_writer.cpp
    solutions/src/html_writer.hpp
)
target_link_libraries(html_writer PRIVATE fmt::fmt)
target_include_directories(html_writer PUBLIC solutions/src)

# image_browser library
add_library(image_browser
    solutions/src/image_browser.cpp
    solutions/src/image_browser.hpp
)
target_link_libraries(image_browser PUBLIC html_writer)
target_include_directories(image_browser PUBLIC solutions/src)

# Executable
add_executable(create_image_browser
    solutions/src/create_image_browser.cpp
)
target_link_libraries(create_image_browser PRIVATE image_browser)

# Output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
