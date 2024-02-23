cmake_minimum_required(VERSION 3.10)

# 设置编译器可用，不进行检测
set(CMAKE_C_COMPILER_WORKS  TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)

# 编译、构建工具路径得在project前设置
set(COMPILE_TOOL_PATH   F:/mingw64/bin)
set(CMAKE_GENERATOR     "MinGW Makefiles")
set(CMAKE_MAKE_PROGRAM  ${COMPILE_TOOL_PATH}/mingw32-make.exe)
set(CMAKE_C_COMPILER    ${COMPILE_TOOL_PATH}/gcc.exe)
set(CMAKE_CXX_COMPILER  ${COMPILE_TOOL_PATH}/g++.exe)

project(SimulateDPU  VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(SRC_PATH ${PROJECT_SOURCE_DIR}/src/main.cpp)

include_directories(include)

message("SRC_PATH = ${SRC_PATH}")

add_executable(SimulateDPU ${SRC_PATH})