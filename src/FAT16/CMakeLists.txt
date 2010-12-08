message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(FAT16 STATIC
byteordering.c
fat.c
partition.c
sd_raw.c
)
