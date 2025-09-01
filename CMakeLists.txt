# Sets the minimum required version of CMake. Boilerplate.
cmake_minimum_required(VERSION 3.15)

# Defines the project name.
project(MDLEX)

# Set the C++ standard you want to use (e.g., C++17).
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake to process the CMakeLists.txt file in the 'src' directory.
add_subdirectory(src)