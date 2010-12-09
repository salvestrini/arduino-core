## http://www.paraview.org/Wiki/CMake_Cross_Compiling

message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

set(ARDUINO_TYPE duemilanove CACHE STRING "Arduino type")

include(arduino-${ARDUINO_TYPE})

set(ARDUINO_C_FLAGS_STANDARD   "-std=gnu99")
set(ARDUINO_C_FLAGS_WARN       "-Wall -Wstrict-prototypes")
set(ARDUINO_C_FLAGS_TUNING     "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums")
set(ARDUINO_C_FLAGS_OPT        "-Os")

set(ARDUINO_CXX_FLAGS_STANDARD "-std=gnu++98")
set(ARDUINO_CXX_FLAGS_WARN     "-Wall")
set(ARDUINO_CXX_FLAGS_TUNING   "-fno-rtti -fno-enforce-eh-specs -fno-threadsafe-statics -fvisibility-inlines-hidden")
set(ARDUINO_CXX_FLAGS_OPT      "-Os")
