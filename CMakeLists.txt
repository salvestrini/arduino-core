cmake_minimum_required(VERSION 2.8)

message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")



set(CMAKE_SYSTEM_NAME      Generic)
set(CMAKE_SYSTEM_VERSION   1)
set(CMAKE_SYSTEM_PROCESSOR avr)

set(CMAKE_C_COMPILER   avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_AR           avr-ar)
set(CMAKE_RANLIB       avr-ranlib)
set(CMAKE_LINKER       avr-ld)

set(CSTANDARD "-std=gnu99")
set(CDEBUG    "-gstabs")
set(CWARN     "-Wall -Wstrict-prototypes")
set(CTUNING   "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -fno-rtti")
set(COPT      "-Os")
set(CMCU      "-mmcu=atmega168")
set(CDEFS     "-DF_CPU=16000000")

set(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS} ${CMCU} ${CDEBUG} ${CDEFS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}")
set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} ${CMCU} ${CDEFS} ${COPT}")
set(CMAKE_EXE_LINKER_FLAGS "")



project(ArduinoCode)

##set(CMAKE_BUILD_TYPE       NONE)
##set(CMAKE_VERBOSE_MAKEFILE OFF)
##set(BUILD_SHARED_LIBS      OFF)
#set(CMAKE_MODULE_PATH      "${CMAKE_SOURCE_DIR}/cmake")
#
#find_program(AVR_GCC_EXECUTABLE     avr-gcc)
#find_program(AVR_GXX_EXECUTABLE     avr-g++)
#find_program(AVR_AR_EXECUTABLE      avr-ar)
#find_program(AVR_RANLIB_EXECUTABLE  avr-ranlib)
#find_program(AVR_LINKER_EXECUTABLE  avr-ld)
#
#set(CMAKE_C_COMPILER   ${AVR_GCC_EXECUTABLE})
#set(CMAKE_CXX_COMPILER ${AVR_GXX_EXECUTABLE})
#set(CMAKE_AR           ${AVR_AR_EXECUTABLE})
#set(CMAKE_RANLIB       ${AVR_RANLIB_EXECUTABLE})
#set(CMAKE_LINKER       ${AVR_LINKER_EXECUTABLE})
#
#include(arduino)

add_subdirectory(utils)
add_subdirectory(libs)
add_subdirectory(src)

#include(FeatureSummary)
#print_enabled_features()
#include(CMakePrintSystemInformation)
