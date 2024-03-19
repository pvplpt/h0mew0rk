cmake_minimum_required(VERSION 3.25)

add_executable(audioPlayerSimulator main.cpp ${MY_INCLUDE_DIR}/Track.h Track.cpp ${MY_INCLUDE_DIR}/AudioPlayer.h AudioPlayer.cpp)
target_include_directories(audioPlayerSimulator PUBLIC ${MY_INCLUDE_DIR})
