message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/libs/Core)
include_directories(${ArduinoCode_BINARY_DIR}/libs/Core)

add_library(Servo STATIC
  Servo.cpp
)
