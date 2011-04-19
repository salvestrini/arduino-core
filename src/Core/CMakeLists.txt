message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include(CheckIncludeFile)

check_include_file(util/delay.h HAVE_UTIL_DELAY_H)
check_include_file(avr/delay.h  HAVE_AVR_DELAY_H)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

include_directories(${CMAKE_SOURCE_DIR}/src/Core)
include_directories(${CMAKE_BINARY_DIR}/src/Core)

add_library(Core STATIC
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
