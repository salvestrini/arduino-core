message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

find_program(AVR_OBJCOPY_EXECUTABLE avr-objcopy)
message(STATUS "Binary ${AVR_OBJCOPY_EXECUTABLE}")

find_program(AVR_SIZE_EXECUTABLE avr-size)
message(STATUS "Binary ${AVR_SIZE_EXECUTABLE}")

find_program(AVRDUDE_EXECUTABLE     avrdude)
message(STATUS "Binary ${AVRDUDE_EXECUTABLE}")

set(AVRDUDE_DEVICE "/dev/ttyUSB0" CACHE FILEPATH "ISP programming device")
set(AVRDUDE_SPEED  "57600"        CACHE STRING   "ISP programming speed")
set(AVRDUDE_FAMILY "m168"         CACHE STRING   "ISP programming family")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/isp.in ${CMAKE_CURRENT_BINARY_DIR}/isp)

add_custom_target(upload ${CMAKE_CURRENT_BINARY_DIR}/isp ${ArduinoCode_BINARY_DIR}/src/image)
add_dependencies(upload image)
