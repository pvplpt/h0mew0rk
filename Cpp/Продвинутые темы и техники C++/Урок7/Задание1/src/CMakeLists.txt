cmake_minimum_required(VERSION 3.25)

add_executable(surgeonSimulator main.cpp ${MY_INCLUDE_DIR}/point.h point.cpp ${MY_INCLUDE_DIR}/surgicalTools.h surgicalTools.cpp)
target_include_directories(surgeonSimulator PUBLIC ${MY_INCLUDE_DIR})
