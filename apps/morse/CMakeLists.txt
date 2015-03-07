project (morse C CXX)

cmake_minimum_required (VERSION 2.8)

set (morse_SOURCES main.cpp Morse.cpp)

set (morse_HEADERS Morse.hpp)
include_directories (${CMAKE_CURRENT_SOURCE_DIR})
include_directories ("../../drivers")

add_executable (morse ${morse_SOURCES} ${morse_HEADERS} ${common_SOURCES})
my_set_target_properties (morse)
target_link_libraries(morse drivers)
