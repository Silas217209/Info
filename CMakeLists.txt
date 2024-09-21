cmake_minimum_required(VERSION 3.10)
project(Info)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(queue queue.cpp)
add_executable(sorted sorted.cpp)
add_executable(stack stack.cpp)
add_executable(stack_sorted stack_sorted.cpp)

