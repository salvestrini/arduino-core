MESSAGE(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

find_program(AVR_OBJCOPY avr-objcopy)
find_program(AVR_DUDE    avrdude)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/isp.in ${CMAKE_CURRENT_BINARY_DIR}/isp)
