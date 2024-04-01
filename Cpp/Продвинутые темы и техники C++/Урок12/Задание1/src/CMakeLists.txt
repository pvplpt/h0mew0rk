cmake_minimum_required(VERSION 3.25)

add_executable(userqueries main.cpp )

target_link_libraries(userqueries PRIVATE cpr::cpr)