cmake_minimum_required(VERSION 3.25)

set(SRC
main.cpp
${MY_INCLUDE_DIR}/Player.h
Player.cpp
${MY_INCLUDE_DIR}/Computer.h
Computer.cpp
${MY_INCLUDE_DIR}/Human.h
Human.cpp
${MY_INCLUDE_DIR}/GameOfMatches.h
GameOfMatches.cpp
)

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDE_DIR})
