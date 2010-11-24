message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/libs/core)
include_directories(${ArduinoCode_BINARY_DIR}/libs/core)

add_library(EEPROM STATIC
  EEPROM.cpp
)
