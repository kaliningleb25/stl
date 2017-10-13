cmake_minimum_required(VERSION 3.8)
project(lab_4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Factorial.cpp Factorial.h)
add_executable(lab_4 ${SOURCE_FILES} Factorial.cpp Factorial.h)