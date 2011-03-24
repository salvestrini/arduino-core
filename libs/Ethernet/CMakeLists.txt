message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${ArduinoCode_SOURCE_DIR}/libs/Core)
include_directories(${ArduinoCode_BINARY_DIR}/libs/Core)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/SPI)
include_directories(${ArduinoCode_SOURCE_DIR}/libs/Ethernet/utility)

add_library(Ethernet STATIC
  Ethernet.cpp
  Client.cpp
  Server.cpp
  Udp.cpp
  utility/w5100.cpp
  utility/socket.cpp
)
