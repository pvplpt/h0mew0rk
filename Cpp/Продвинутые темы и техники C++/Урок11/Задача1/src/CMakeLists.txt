cmake_minimum_required(VERSION 3.25)

add_executable(superdog main.cpp ${MY_INCLUDE_DIR}/Dog.h Dog.cpp ${MY_INCLUDE_DIR}/Talent.h Talent.cpp ${MY_INCLUDE_DIR}/Counting.h Counting.cpp ${MY_INCLUDE_DIR}/Dancing.h Dancing.cpp ${MY_INCLUDE_DIR}/Swimming.h Swimming.cpp)
target_include_directories(superdog PUBLIC ${MY_INCLUDE_DIR})
