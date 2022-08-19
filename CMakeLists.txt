cmake_minimum_required(VERSION 3.1)

project(binary_tree)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES "src/*.c")


add_executable(binary_tree ${SOURCES})