message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/libs/core)
include_directories(${ArduinoCode_BINARY_DIR}/libs/core)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/Wire/utility)

add_library(Wire STATIC
  Wire.cpp
)
