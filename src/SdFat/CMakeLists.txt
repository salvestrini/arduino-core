message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(SdFat STATIC
  Sd2Card.cpp
  SdFile.cpp
  SdVolume.cpp
)
