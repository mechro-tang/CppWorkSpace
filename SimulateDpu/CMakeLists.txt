cmake_minimum_required(VERSION 3.1.0)

##### 编译环境设置 #####

# 设置编译器可用，不进行检测
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER_WORKS  TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)

# 编译、构建工具路径（得在project前设置）
if(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")

set(CMAKE_GENERATOR     "MinGW Makefiles")                          # 生成器
set(COMPILE_TOOL_PATH   F:/w64devkit/bin)                           # 编译工具路径
set(CMAKE_MAKE_PROGRAM  ${COMPILE_TOOL_PATH}/mingw32-make.exe)      # 
set(CMAKE_C_COMPILER    ${COMPILE_TOOL_PATH}/gcc.exe)               # C编译工具
set(CMAKE_CXX_COMPILER  ${COMPILE_TOOL_PATH}/g++.exe) 

elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")

else()

message(WARNING "Unsupported operation system: ${CMAKE_HOST_SYSTEM_NAME}")

endif()

message(STATUS "##### 编译环境设置 #####")
message(STATUS "CMAKE_HOST_SYSTEM_NAME  = ${CMAKE_HOST_SYSTEM_NAME}")
message(STATUS "CMAKE_MAKE_PROGRAM      = ${CMAKE_MAKE_PROGRAM}")
message(STATUS "CMAKE_GENERATOR         = ${CMAKE_GENERATOR}")
message(STATUS "CMAKE_C_COMPILER        = ${CMAKE_C_COMPILER}") 
message(STATUS "CMAKE_CXX_COMPILER      = ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_STANDARD      = C++${CMAKE_CXX_STANDARD}")

##### 项目设置 #####

set(CMAKE_BUILD_TYPE    "Debug")
project(EmulateDPU LANGUAGES CXX VERSION 0.1.0) 

# 设置链接库目录 PROJECT_SOURCE_DIR得在project后使用
if(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")

# 链接库目录
set(LINK_LIBRARIES_PATH ${PROJECT_SOURCE_DIR}/lib/Win64/ftxui-5.0.0-win64/lib)
# 静态库需要全路径
set(LINK_LIBRARIES_FILES 
    ${LINK_LIBRARIES_PATH}/ftxui-component.lib
    ${LINK_LIBRARIES_PATH}/ftxui-dom.lib
    ${LINK_LIBRARIES_PATH}/ftxui-screen.lib
)

elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")

endif() 

# ftxui路径
set(ftxui_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/Win64/ftxui-5.0.0-win64/lib/cmake/ftxui)
find_package(ftxui REQUIRED)

# 设置源文件
set(SRC_FILES 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/UserInterface/HomePage.h
    ${PROJECT_SOURCE_DIR}/src/UserInterface/HomePage.cpp
) 


# 设置包含目录
include_directories(${PROJECT_SOURCE_DIR}/include)
# 设置链接库目录
link_directories(${LINK_LIBRARIES_PATH})
link_libraries(${LINK_LIBRARIES_FILES})

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)
add_executable(${PROJECT_NAME} ${SRC_FILES})   

target_link_libraries(${PROJECT_NAME} 
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
    ${LINK_LIBRARIES_FILES}
)

message(STATUS "##### 项目设置 #####")
message(STATUS "PROJECT_NAME            = ${PROJECT_NAME}")
message(STATUS "SRC_FILES               = ${SRC_FILES}")
message(STATUS "include_directories     = ${PROJECT_SOURCE_DIR}/include")
message(STATUS "link_directories        = ${LINK_LIBRARIES_PATH}")
message(STATUS "LINK_LIBRARIES_FILES    = ${LINK_LIBRARIES_FILES}")
message(STATUS "ftxui_DIR               = ${ftxui_DIR}")
message(STATUS "ftxui_INCLUDE_DIRS      = ${ftxui_INCLUDE_DIRS}")
message(STATUS "ftxui_LIBS              = ${ftxui_LIBS}")