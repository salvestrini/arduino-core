message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/src/LED)
include_directories(${ArduinoCode_BINARY_DIR}/src/LED)

add_library(LED STATIC
  LED.cpp
)
