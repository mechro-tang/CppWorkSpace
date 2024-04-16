<<<<<<< HEAD
# Install script for directory: C:/Repositories/Visual Studio Code/CppWorkSpace/SimulateDpu

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Demo")
=======
# Install script for directory: E:/workspace/CppWorkSpace/SimulateDpu

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/EmulateDPU")
>>>>>>> 15543f1a1417205d5a38bf60c05e09e1f2904272
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
<<<<<<< HEAD
  set(CMAKE_OBJDUMP "C:/Program Files/mingw64/bin/objdump.exe")
=======
  set(CMAKE_OBJDUMP "F:/w64devkit/bin/objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/workspace/CppWorkSpace/SimulateDpu/build/lib/FTXUI-5.0.0/cmake_install.cmake")
>>>>>>> 15543f1a1417205d5a38bf60c05e09e1f2904272
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "C:/Repositories/Visual Studio Code/CppWorkSpace/SimulateDpu/build/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "E:/workspace/CppWorkSpace/SimulateDpu/build/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 15543f1a1417205d5a38bf60c05e09e1f2904272
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
