cmake_minimum_required(VERSION 3.25)

set(SRC main.cpp)

set(SRC_LIB
${MY_INCLUDE_DIR}/Player.h
Player.cpp
${MY_INCLUDE_DIR}/Computer.h
Computer.cpp
${MY_INCLUDE_DIR}/Human.h
Human.cpp
${MY_INCLUDE_DIR}/GameOfMatches.h
GameOfMatches.cpp
)

add_library(libmygame SHARED ${SRC_LIB})
set_target_properties(libmygame PROPERTIES OUTPUT_NAME mygame)
target_include_directories(libmygame PUBLIC ${MY_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} libmygame)

