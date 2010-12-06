message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/src/AFSoftSerial)
include_directories(${ArduinoCode_BINARY_DIR}/src/AFSoftSerial)

add_library(AFSoftSerial STATIC
  AFSoftSerial.cpp
)
