## http://www.paraview.org/Wiki/CMake_Cross_Compiling
#
#message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")
#
#set(ARDUINO_TYPE diecimila CACHE STRING "Arduino type")
#
#include(arduino-${ARDUINO_TYPE})
#
#set(C_FLAGS_STANDARD   "-std=gnu99")
#set(C_FLAGS_WARN       "-Wall -Wstrict-prototypes")
#set(C_FLAGS_TUNING     "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums")
#set(C_FLAGS_OPT        "-Os")
#
#set(CXX_FLAGS_STANDARD "-std=gnu++98")
#set(CXX_FLAGS_WARN     "-Wall")
#set(CXX_FLAGS_TUNING   "")
#set(CXX_FLAGS_OPT      "-Os")
#
#set(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS}   ${ARDUINO_MCU} ${ARDUINO_DEFS} ${ARDUINO_C_FLAGS_OPT}   ${ARDUINO_C_FLAGS_STANDARD}   ${ARDUINO_C_FLAGS_WARN}   ${ARDUINO_C_FLAGS_TUNING}  ")
#set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} ${ARDUINO_MCU} ${ARDUINO_DEFS} ${ARDUINO_CXX_FLAGS_OPT} ${ARDUINO_CXX_FLAGS_STANDARD} ${ARDUINO_CXX_FLAGS_WARN} ${ARDUINO_CXX_FLAGS_TUNING}")
#set(CMAKE_EXE_LINKER_FLAGS "")
