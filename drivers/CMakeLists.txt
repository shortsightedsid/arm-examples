project (drivers C CXX)

cmake_minimum_required (VERSION 2.8)

set (drivers_SOURCES Led.cpp)

set (drivers_HEADERS Led.hpp)
include_directories (${CMAKE_CURRENT_SOURCE_DIR})
include_directories ("../utils")

add_library (drivers ${drivers_SOURCES} ${drivers_HEADERS})
my_set_target_properties (drivers)