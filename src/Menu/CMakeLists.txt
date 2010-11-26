message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/src/Menu)
include_directories(${ArduinoCode_BINARY_DIR}/src/Menu)

add_library(Menu STATIC
  Menu.cpp
)
