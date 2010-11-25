message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/src/SerLCD)
include_directories(${ArduinoCode_BINARY_DIR}/src/SerLCD)

add_library(SerLCD STATIC
  SerLCD.cpp
)
