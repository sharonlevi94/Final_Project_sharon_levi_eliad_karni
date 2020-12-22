# CMakeList.txt : CMake project for Final_Project_sharon_levi_eliad_karni, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

project ("Final_Project_sharon_levi_eliad_karni")
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/permissive-)
endif ()
# Add source to this project's executable.
#//add_executable (Final_Project_sharon_levi_eliad_karni "Final_Project_sharon_levi_eliad_karni.cpp" "Final_Project_sharon_levi_eliad_karni.h" "include/Controller.h" "include/Board.h" "include/Menu.h" "include/DataReader.h" "include/EffectsHolder.h" "include/GameState.h" "include/.h")
add_executable (Final_Project_sharon_levi_eliad_karni "")
add_subdirectory (include)
add_subdirectory (src)
#//add_subdirectory (resources)
# TODO: Add tests and install targets if needed.

set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR "C:/SFML/SFML-2.5.1/lib/cmake/SFML")

find_package (SFML 2.5 COMPONENTS graphics REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (Final_Project_sharon_levi_eliad_karni sfml-graphics sfml-main)
