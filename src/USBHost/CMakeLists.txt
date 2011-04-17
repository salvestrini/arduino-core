message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(USBHost STATIC
  Max3421e.cpp
  Max_LCD.cpp
  Usb.cpp
)
