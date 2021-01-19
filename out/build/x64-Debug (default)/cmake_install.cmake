<<<<<<< HEAD
# Install script for directory: D:/Projects/Visual Studio Projects/gitHub/Final_Project_sharon_levi_eliad_karni

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/Projects/Visual Studio Projects/gitHub/Final_Project_sharon_levi_eliad_karni/out/install/x64-Debug (default)")
=======
# Install script for directory: C:/Users/sharonlevi/source/repos/Final_Project_sharon_levi_eliad_karni

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/sharonlevi/source/repos/Final_Project_sharon_levi_eliad_karni/out/install/x64-Debug (default)")
>>>>>>> 1d959ef48beac07cf666c7dbd64d6045dfddedb4
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
<<<<<<< HEAD
  include("D:/Projects/Visual Studio Projects/gitHub/Final_Project_sharon_levi_eliad_karni/out/build/x64-Debug (default)/include/cmake_install.cmake")
=======
  include("C:/Users/sharonlevi/source/repos/Final_Project_sharon_levi_eliad_karni/out/build/x64-Debug (default)/include/cmake_install.cmake")
>>>>>>> 1d959ef48beac07cf666c7dbd64d6045dfddedb4
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
<<<<<<< HEAD
  include("D:/Projects/Visual Studio Projects/gitHub/Final_Project_sharon_levi_eliad_karni/out/build/x64-Debug (default)/src/cmake_install.cmake")
=======
  include("C:/Users/sharonlevi/source/repos/Final_Project_sharon_levi_eliad_karni/out/build/x64-Debug (default)/src/cmake_install.cmake")
>>>>>>> 1d959ef48beac07cf666c7dbd64d6045dfddedb4
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
<<<<<<< HEAD
  include("D:/Projects/Visual Studio Projects/gitHub/Final_Project_sharon_levi_eliad_karni/out/build/x64-Debug (default)/resources/cmake_install.cmake")
=======
  include("C:/Users/sharonlevi/source/repos/Final_Project_sharon_levi_eliad_karni/out/build/x64-Debug (default)/resources/cmake_install.cmake")
>>>>>>> 1d959ef48beac07cf666c7dbd64d6045dfddedb4
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "D:/Projects/Visual Studio Projects/gitHub/Final_Project_sharon_levi_eliad_karni/out/build/x64-Debug (default)/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "C:/Users/sharonlevi/source/repos/Final_Project_sharon_levi_eliad_karni/out/build/x64-Debug (default)/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 1d959ef48beac07cf666c7dbd64d6045dfddedb4
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
