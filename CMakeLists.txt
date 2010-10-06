cmake_minimum_required(VERSION 2.6)

project(ArduinoCode)

#include(${ArduinoCode_SOURCE_DIR}/cmake/arduino_diecimila_crosscompile.cmake)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(arduino_diecimila_crosscompile)

add_subdirectory(libs)
add_subdirectory(src)

include(FeatureSummary)
print_enabled_features()

#include(CMakePrintSystemInformation)
