cmake_minimum_required(VERSION 3.25)
project("Computer simulator" VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

