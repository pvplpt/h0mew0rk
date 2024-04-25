cmake_minimum_required(VERSION 3.25)
project(matches CXX)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)

