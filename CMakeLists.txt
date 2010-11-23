cmake_minimum_required(VERSION 2.8)

MESSAGE(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")




set(CMAKE_SYSTEM_NAME      Generic)
set(CMAKE_SYSTEM_VERSION   1)
set(CMAKE_SYSTEM_PROCESSOR avr)

# specify the cross compiler
#CMAKE_FORCE_C_COMPILER(avr-gcc   GNU)
#CMAKE_FORCE_CXX_COMPILER(avr-g++ GNU)

#SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

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

set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${CMCU} ${CDEBUG} ${CDEFS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMCU} ${CDEFS} ${COPT}")
set(CMAKE_EXE_LINKER_FLAGS "")




project(ArduinoCode)

#set(CMAKE_BUILD_TYPE       NONE)
#set(CMAKE_VERBOSE_MAKEFILE OFF)
#set(BUILD_SHARED_LIBS      OFF)
set(CMAKE_MODULE_PATH      "${CMAKE_SOURCE_DIR}/cmake")

include(arduino-diecimila)

add_subdirectory(libs)
add_subdirectory(src)

#include(FeatureSummary)
#print_enabled_features()

#include(CMakePrintSystemInformation)
