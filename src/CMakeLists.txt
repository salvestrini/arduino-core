include(${ArduinoCode_SOURCE_DIR}/arduino_diecimila_crosscompile.cmake)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/core)
LINK_DIRECTORIES(${ArduinoCode_SOURCE_DIR}/libs/core)

link_libraries(arduinocore)

add_executable(blinkLED blinkLED.cc)
