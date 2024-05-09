cmake_minimum_required(VERSION 3.6)
PROJECT(tic_tac_toe_client CXX)

SET(NTTC_SRC client.cpp gamemanager.cpp simpleboard.cpp consoleplayer.cpp consolegame.cpp)

add_executable(${PROJECT_NAME} ${NTTC_SRC})
#target_include_directories(${PROJECT_NAME} PRIVATE  ${Boost_INCLUDE_DIRS})
#target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )
