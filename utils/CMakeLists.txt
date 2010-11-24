message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

find_program(AVR_OBJCOPY avr-objcopy)
message(STATUS "Binary ${AVR_OBJCOPY}")

find_program(AVR_DUDE    avrdude)
message(STATUS "Binary ${AVR_DUDE}")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/isp.in ${CMAKE_CURRENT_BINARY_DIR}/isp)
