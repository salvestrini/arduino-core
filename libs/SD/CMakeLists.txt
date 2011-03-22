message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/libs/Core)
include_directories(${ArduinoCode_BINARY_DIR}/libs/Core)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/SD)

add_library(SD STATIC
  SD.cpp
)
