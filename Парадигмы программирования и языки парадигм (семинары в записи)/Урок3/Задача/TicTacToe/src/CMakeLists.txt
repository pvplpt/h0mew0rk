cmake_minimum_required(VERSION 3.25)

add_executable(tictactoe main.cpp ${MY_INCLUDE_DIR}/Player.h Player.cpp ${MY_INCLUDE_DIR}/Board.h Board.cpp ${MY_INCLUDE_DIR}/Game.h Game.cpp)
target_include_directories(tictactoe PUBLIC ${MY_INCLUDE_DIR})
