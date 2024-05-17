# Project settings
cmake_minimum_required(VERSION 3.0)

project(
    ansi
    LANGUAGES CXX
)

# Compilation settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "-g -Wall -Wextra -ansi -pedantic-errors")

# Add the include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add subdirectories for examples
add_subdirectory(examples)