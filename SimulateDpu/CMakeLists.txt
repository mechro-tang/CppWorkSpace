cmake_minimum_required(VERSION 3.11)

# 设置编译器可用，不进行检测
set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 编译、构建工具路径（得在project前设置） 
set(CMAKE_GENERATOR     "MinGW Makefiles")                           # 生成器
set(COMPILE_TOOL_PATH   "C:/Program Files/mingw64/bin")
set(CMAKE_MAKE_PROGRAM  ${COMPILE_TOOL_PATH}/mingw32-make.exe)
set(CMAKE_C_COMPILER    ${COMPILE_TOOL_PATH}/gcc.exe)
set(CMAKE_CXX_COMPILER  ${COMPILE_TOOL_PATH}/g++.exe)  

project(Demo LANGUAGES CXX)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(print 
    ${PROJECT_SOURCE_DIR}/src/print.cpp
    ${PROJECT_SOURCE_DIR}/src/print.h
)

set(CMAKE_BUILD_TYPE "Release")
add_executable(${PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

set(LINK_FILES
    ${PROJECT_SOURCE_DIR}/lib/Win64/ftxui-dom.lib
    ${PROJECT_SOURCE_DIR}/lib/Win64/ftxui-component.lib
    ${PROJECT_SOURCE_DIR}/lib/Win64/ftxui-screen.lib
)

# link_libraries(
#     ${LINK_FILES}
# )

set_target_properties(print PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME}
    print
    ${LINK_FILES}
)

message(STATUS "LINK_FILES = ${LINK_FILES}")

###########################################################################

# # 程序编译参照官方的cmake示例
# cmake_minimum_required (VERSION 3.11)
 
# # --- Fetch FTXUI --------------------------------------------------------------
# include(FetchContent)
 
# set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
# FetchContent_Declare(ftxui
#   GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
#   # Important: Specify a GIT_TAG XXXXX here.
# )
 
# FetchContent_GetProperties(ftxui)
# if(NOT ftxui_POPULATED)
#   FetchContent_Populate(ftxui)
#   add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
# endif()
 
# # ------------------------------------------------------------------------------
 
# project(ftxui-starter
#   LANGUAGES CXX
#   VERSION 1.0.0
# )
 
# add_executable(ftxui-starter src/main.cpp)
# target_include_directories(ftxui-starter PRIVATE src)
 
# target_link_libraries(ftxui-starter
#   PRIVATE ftxui::screen
#   PRIVATE ftxui::dom
#   PRIVATE ftxui::component # Not needed for this example.
# )