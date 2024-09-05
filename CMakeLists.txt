cmake_minimum_required(VERSION 3.18)

set(PROJECT_NAME "pss_project")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set(CMAKE_CXX_COMPILER ${COMPILER_PATH})

message(STATUS "--- Building ${PROJECT_NAME} ---")
add_subdirectory(software)
