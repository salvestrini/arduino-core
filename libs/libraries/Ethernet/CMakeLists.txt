message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/libs/core)
include_directories(${ArduinoCode_BINARY_DIR}/libs/core)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/SPI)
include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/Ethernet/utility)

add_library(Ethernet STATIC
  Client.cpp
  Server.cpp
  Udp.cpp
)
