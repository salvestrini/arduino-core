# http://www.paraview.org/Wiki/CMake_Cross_Compiling

message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

#include(CMakeForceCompiler)

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
set(CTUNING   "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums")
set(COPT      "-Os")
set(CMCU      "-mmcu=atmega168")
set(CDEFS     "-DF_CPU=16000000")

set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${CMCU} ${CDEBUG} ${CDEFS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMCU} ${CDEFS} ${COPT}")
set(CMAKE_EXE_LINKER_FLAGS "")
