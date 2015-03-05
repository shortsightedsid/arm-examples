project (morse C CXX)

cmake_minimum_required (VERSION 2.8)

set (morse_SOURCES main.cpp Led.cpp Morse.cpp)

set (morse_HEADERS Led.hpp Morse.hpp)
include_directories (${CMAKE_CURRENT_SOURCE_DIR})

add_executable (morse ${morse_SOURCES} ${morse_HEADERS} ${common_SOURCES})
my_set_target_properties (morse)
