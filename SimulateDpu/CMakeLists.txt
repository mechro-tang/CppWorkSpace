cmake_minimum_required(VERSION 3.10)

set(COMPILE_TOOL_PATH   F:/w64devkit/bin)
set(CMAKE_GENERATOR     "MinGW Makefiles")
set(CMAKE_MAKE_PROGRAM  ${COMPILE_TOOL_PATH}/mingw32-make.exe)
set(CMAKE_C_COMPILER    ${COMPILE_TOOL_PATH}/gcc.exe)
set(CMAKE_CXX_COMPILER  ${COMPILE_TOOL_PATH}/g++.exe)

project(SimulateDPU VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

set(SRC_PATH 
    src/main.cpp
)

set(INCLUDE_PATH
    include/
)

include_directories(include)

add_executable(SimulateDPU ${SRC_PATH})