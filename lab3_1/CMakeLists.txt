cmake_minimum_required(VERSION 3.8)
project(lab3_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp QueueWithPriority.h)
add_executable(lab3_1 ${SOURCE_FILES} QueueWithPriority.h)