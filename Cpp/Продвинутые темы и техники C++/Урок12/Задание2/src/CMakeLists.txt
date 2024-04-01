cmake_minimum_required(VERSION 3.25)

add_executable(headercapture main.cpp )

target_link_libraries(headercapture PRIVATE cpr::cpr)