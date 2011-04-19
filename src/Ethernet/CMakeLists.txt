message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${CMAKE_SOURCE_DIR}/src/Core)
include_directories(${CMAKE_BINARY_DIR}/src/Core)

include_directories(${CMAKE_SOURCE_DIR}/src/SPI)
include_directories(${CMAKE_SOURCE_DIR}/src/Ethernet/utility)

add_library(Ethernet STATIC
  Ethernet.cpp
  Client.cpp
  Server.cpp
  Udp.cpp
  utility/w5100.cpp
  utility/socket.cpp
)
