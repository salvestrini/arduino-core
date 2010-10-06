#include(${ArduinoCode_SOURCE_DIR}/cmake/arduino_diecimila_crosscompile.cmake)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/core)

link_directories(${ArduinoCode_SOURCE_DIR}/libs/core)

add_executable(blinkLED
  blinkLED.cc)

target_link_libraries(blinkLED core)
