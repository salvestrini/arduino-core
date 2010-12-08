message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/src/Fat16)
include_directories(${ArduinoCode_BINARY_DIR}/src/Fat16)

add_library(Fat16 STATIC
  Fat16.cpp
  SdCard.cpp
)
