cmake_minimum_required(VERSION 3.6)
PROJECT(tic_tac_toe CXX)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
#find_package(Boost 1.71.0 COMPONENTS program_options unit_test_framework REQUIRED HINTS "/Users/a1111/Dev/Distr/Cpp/boost/boost_1_71_0_t")

#IF (NOT Boost_FOUND)
#        message(FATAL_ERROR "Boost not found")
#ENDIF()

message(STATUS "Boost FOUND")
message("boost include dirs = ${Boost_INCLUDE_DIRS}")
message("boost dir release = ${Boost_LIBRARY_DIR_RELEASE}")
message("boost libraries =  ${Boost_LIBRARIES}")

add_subdirectory(client)
add_subdirectory(server)
