cmake_minimum_required(VERSION 3.10)
project(first_lib_project)
set(CMAKE_CXX_STANDARD 17) # std=c++17
set(SMAKE_EXPORT_COMPILE_COMMANDS ON) # important
add_library(tools tools.cpp)
add_executable(main main.cpp)
target_link_libraries(main tools)
