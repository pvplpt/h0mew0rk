cmake_minimum_required(VERSION 3.25)

add_executable(querieswithargs main.cpp )

target_link_libraries(querieswithargs PRIVATE cpr::cpr)