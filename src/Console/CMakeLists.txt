message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/src/Console)
include_directories(${ArduinoCode_BINARY_DIR}/src/Console)

add_library(Console STATIC
  Console.cpp
)
