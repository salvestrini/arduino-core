message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/src/SD)
include_directories(${ArduinoCode_BINARY_DIR}/src/SD)

add_library(SD STATIC
  SD.cpp
)
