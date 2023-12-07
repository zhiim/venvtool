# CMake lowest version requirement
cmake_minimum_required(VERSION 3.5.1)

# project information
project(venvtool)

# Compile options
add_compile_options(-std=c++17)

# Specify target generation path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "../out")
set(CMAKE_CXX_FLAGS_DEBUG "-fPIC -O0 -g -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-fPIC -O2 -Wall")

# Header path
include_directories(
    include
)

# add host lib path
# link_directories()

add_executable(venvtool
        src/main.cpp
        src/venvtool.cpp)

# target_link_libraries()

install(TARGETS venvtool DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
