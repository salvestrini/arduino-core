message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/src/SdFat)
include_directories(${ArduinoCode_BINARY_DIR}/src/SdFat)

add_library(SdFat STATIC
  Sd2Card.cpp
  SdFile.cpp
  SdVolume.cpp
)
