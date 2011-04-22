cmake_minimum_required(VERSION 2.8)

message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/extras/cmake")

set(CMAKE_SYSTEM_NAME      Generic)
set(CMAKE_SYSTEM_VERSION   1)
set(CMAKE_SYSTEM_PROCESSOR avr)

#set(CMAKE_BUILD_TYPE       NONE)
#set(CMAKE_VERBOSE_MAKEFILE OFF)
#set(BUILD_SHARED_LIBS      OFF)

#set(CMAKE_C_COMPILER   avr-gcc)
#set(CMAKE_CXX_COMPILER avr-g++)
#set(CMAKE_AR           avr-ar)
#set(CMAKE_RANLIB       avr-ranlib)
#set(CMAKE_LINKER       avr-ld)

find_program(AVR_GCC_EXECUTABLE     avr-gcc)
find_program(AVR_GXX_EXECUTABLE     avr-g++)
find_program(AVR_AR_EXECUTABLE      avr-ar)
find_program(AVR_RANLIB_EXECUTABLE  avr-ranlib)
find_program(AVR_LINKER_EXECUTABLE  avr-ld)

set(CMAKE_C_COMPILER   ${AVR_GCC_EXECUTABLE})
set(CMAKE_CXX_COMPILER ${AVR_GXX_EXECUTABLE})

project(ArduinoBuild)

set(CMAKE_AR           ${AVR_AR_EXECUTABLE})
set(CMAKE_RANLIB       ${AVR_RANLIB_EXECUTABLE})
set(CMAKE_LINKER       ${AVR_LINKER_EXECUTABLE})

include(arduino)

set(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS}   ${ARDUINO_MCU} ${ARDUINO_DEFS} ${ARDUINO_C_FLAGS_OPT}   ${ARDUINO_C_FLAGS_STANDARD}   ${ARDUINO_C_FLAGS_WARN}   ${ARDUINO_C_FLAGS_TUNING}  ")
set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} ${ARDUINO_MCU} ${ARDUINO_DEFS} ${ARDUINO_CXX_FLAGS_OPT} ${ARDUINO_CXX_FLAGS_STANDARD} ${ARDUINO_CXX_FLAGS_WARN} ${ARDUINO_CXX_FLAGS_TUNING}")
set(CMAKE_EXE_LINKER_FLAGS "")

add_subdirectory(extras)
add_subdirectory(src)

include(FeatureSummary)
print_enabled_features()

#include(CMakePrintSystemInformation)
