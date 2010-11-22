MESSAGE(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include(CheckIncludeFile)

check_include_file(util/delay.h UTIL_DELAY_H)
check_include_file(avr/delay.h  AVR_DELAY_H)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/core)

add_library(core STATIC
  HardwareSerial.cpp
  Print.cpp
  Tone.cpp
  WInterrupts.c
  WMath.cpp
  WString.cpp
  main.cpp
  pins_arduino.c
  wiring.c
  wiring_analog.c
  wiring_digital.c
  wiring_pulse.c
  wiring_shift.c
)
