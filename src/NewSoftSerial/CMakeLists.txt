message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/src/NewSoftSerial)
include_directories(${ArduinoCode_BINARY_DIR}/src/NewSoftSerial)

add_library(NewSoftSerial STATIC
  NewSoftSerial.cpp
)
