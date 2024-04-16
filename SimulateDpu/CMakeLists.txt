<<<<<<< HEAD
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
=======
cmake_minimum_required(VERSION 3.20.0)

##### enviroment setting #####

# set compiler
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_C_COMPILER_WORKS      TRUE)
set(CMAKE_CXX_COMPILER_WORKS    TRUE)
 
if(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")    # windows
#!!!!! 设置生成器"MinGW Makefiles"会导致编译失败，默认Unix Makefiles !!!!!#
#set(CMAKE_GENERATOR     "MinGW Makefiles")                          
set(COMPILE_TOOL_PATH   F:/w64devkit/bin)                           
set(CMAKE_MAKE_PROGRAM  ${COMPILE_TOOL_PATH}/mingw32-make.exe)      
set(CMAKE_C_COMPILER    ${COMPILE_TOOL_PATH}/gcc.exe)               
set(CMAKE_CXX_COMPILER  ${COMPILE_TOOL_PATH}/g++.exe) 

elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")

else()

message(WARNING "Unsupported operation system: ${CMAKE_HOST_SYSTEM_NAME}")

endif()

message(STATUS "##### enviroment setting #####")
message(STATUS "CMAKE_HOST_SYSTEM_NAME      = ${CMAKE_HOST_SYSTEM_NAME}")
message(STATUS "CMAKE_MAKE_PROGRAM          = ${CMAKE_MAKE_PROGRAM}")
message(STATUS "CMAKE_GENERATOR             = ${CMAKE_GENERATOR}")
message(STATUS "CMAKE_C_COMPILER            = ${CMAKE_C_COMPILER}") 
message(STATUS "CMAKE_CXX_COMPILER          = ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_STANDARD          = C++${CMAKE_CXX_STANDARD}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR      = C++${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_GENERATOR_PLATFORM    = C++${CMAKE_GENERATOR_PLATFORM}")
##### project setting #####

set(CMAKE_BUILD_TYPE    "Release")
project(EmulateDPU LANGUAGES CXX VERSION 0.1.0) 

# 
set(SRC_FILES 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/jsoncpp.cpp
    ${PROJECT_SOURCE_DIR}/src/UserInterface/HomePage.h
    ${PROJECT_SOURCE_DIR}/src/UserInterface/HomePage.cpp
) 

# add lib ftx-ui
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/FTXUI-5.0.0)
#add_subdirectory(${PROJECT_SOURCE_DIR}/lib/jsoncpp-master)

include_directories(${PROJECT_SOURCE_DIR}/include)

# 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)
add_executable(EmulateDPU ${SRC_FILES})   

target_link_libraries(${PROJECT_NAME} 
    ftxui::component
    ftxui::dom
    ftxui::screen
)

message(STATUS "##### project setting #####")
message(STATUS "PROJECT_NAME            = ${PROJECT_NAME}")
message(STATUS "SRC_FILES               = ${SRC_FILES}")
message(STATUS "include_directories     = ${PROJECT_SOURCE_DIR}/include")
message(STATUS "link_directories        = ${LINK_LIBRARIES_PATH}")
message(STATUS "LINK_LIBRARIES_FILES    = ${LINK_LIBRARIES_FILES}")
>>>>>>> 15543f1a1417205d5a38bf60c05e09e1f2904272
