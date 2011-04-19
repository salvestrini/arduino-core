message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${CMAKE_SOURCE_DIR}/src/Core)
include_directories(${CMAKE_BINARY_DIR}/src/Core)

include_directories(${CMAKE_SOURCE_DIR}/src/Sprite)

add_library(Matrix STATIC
  Matrix.cpp
)
