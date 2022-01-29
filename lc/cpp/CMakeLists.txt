project(kuro3d)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_BUILD_TYPE Debug)

# Add header path
include_directories(${CMAKE_SOURCE_DIR})


add_subdirectory(src)