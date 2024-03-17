cmake_minimum_required(VERSION 3.25)

add_executable(PCSimulator main.cpp ${MY_INCLUDE_DIR}/cpu.h cpu.cpp ${MY_INCLUDE_DIR}/disk.h disk.cpp ${MY_INCLUDE_DIR}/gpu.h gpu.cpp ${MY_INCLUDE_DIR}/kbd.h kbd.cpp ${MY_INCLUDE_DIR}/ram.h ram.cpp)
target_include_directories(PCSimulator PUBLIC ${MY_INCLUDE_DIR})
