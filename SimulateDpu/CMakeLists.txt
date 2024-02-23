cmake_minimum_required(VERSION 3.1.0)

# 设置编译器可用，不进行检测
set(CMAKE_C_COMPILER_WORKS  TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)

# 编译、构建工具路径（得在project前设置） 
set(CMAKE_GENERATOR     "MinGW Makefiles")                           # 生成器
set(COMPILE_TOOL_PATH   F:/w64devkit/bin)
set(CMAKE_MAKE_PROGRAM  ${COMPILE_TOOL_PATH}/mingw32-make.exe)
set(CMAKE_C_COMPILER    ${COMPILE_TOOL_PATH}/gcc.exe)
set(CMAKE_CXX_COMPILER  ${COMPILE_TOOL_PATH}/g++.exe) 

message("CMAKE_MAKE_PROGRAM = ${CMAKE_MAKE_PROGRAM}")
message("CMAKE_C_COMPILER   = ${CMAKE_C_COMPILER}") 
message("CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}")

project(SimulateDPU VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

# 设置源文件
set(SRC_FILES 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/UserInterface/HomePage.h
    ${PROJECT_SOURCE_DIR}/src/UserInterface/HomePage.cpp
)

# 设置包含目录
include_directories(${PROJECT_SOURCE_DIR}/include/)
message("include_directories = ${PROJECT_SOURCE_DIR}/include")

set(CMAKE_BUILD_TYPE    "Release") 
# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)
add_executable(${PROJECT_NAME} ${SRC_FILES})   

# 设置链接库目录
set(LINK_LIBRARIES_PATH ${PROJECT_SOURCE_DIR}/lib/Win64)
# 设置链接库
set(LINK_LIBRARIES_FILES 
    ${LINK_LIBRARIES_PATH}/ftxui-component.lib 
    ${LINK_LIBRARIES_PATH}/ftxui-dom.lib
    ${LINK_LIBRARIES_PATH}/ftxui-screen.lib
)

target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES_FILES})
message("LINK_LIBRARIES_FILES = ${LINK_LIBRARIES_FILES}")