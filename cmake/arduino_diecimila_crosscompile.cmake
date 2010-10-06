# http://www.paraview.org/Wiki/CMake_Cross_Compiling

set(CMAKE_SYSTEM_NAME      Generic)
set(CMAKE_SYSTEM_PROCESSOR arduino2009)

enable_language(C)
enable_language(CXX)

set(CMAKE_C_COMPILER   avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_AR           avr-ar)
set(CMAKE_RANLIB       avr-ranlib)
set(CMAKE_LINKER       avr-ld)

set(BUILD_SHARED_LIBS OFF)
##set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS FALSE)
#set(CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS   "-static")
#set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "-static")

#if(BUILD_STATIC_EXECUTABLES)
#  echo("Dynamic")
#  #set(CMAKE_EXE_LINKER_FLAGS -static)
#  #set(CMAKE_FIND_LIBRARY_SUFFIXES .a)
#  #set(CMAKE_EXE_LINK_DYNAMIC_C_FLAGS)       # remove -Wl,-Bdynamic
#  #set(CMAKE_EXE_LINK_DYNAMIC_CXX_FLAGS)
#  #set(CMAKE_SHARED_LIBRARY_C_FLAGS)         # remove -fPIC
#  #set(CMAKE_SHARED_LIBRARY_CXX_FLAGS)
#  #set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)    # remove -rdynamic
#  #set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)
#  ## Maybe this works as well, haven't tried yet.
#  ## set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS FALSE)
#else(BUILD_STATIC_EXECUTABLES)
#  echo("Static")
#  ## Set RPATH to use for installed targets; append linker search path
#  #set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${LOFAR_LIBDIR}")
#  #set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
#endif(BUILD_STATIC_EXECUTABLES)

set(CSTANDARD "-std=gnu99")
set(CDEBUG    "-gstabs")
set(CWARN     "-Wall -Wstrict-prototypes")
set(CTUNING   "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums")
set(COPT      "-Os")
set(CINCS     "-I${ArduinoCode_SOURCE_DIR}/libs/core")
set(CMCU      "-mmcu=atmega168")
set(CDEFS     "-DF_CPU=16000000")

set(CMAKE_C_FLAGS   "${CMCU} ${CDEBUG} ${CDEFS} ${CINCS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}")
set(CMAKE_CXX_FLAGS "${CMCU} ${CDEFS} ${CINCS} ${COPT}")

#set(LINK_FLAGS      "-static")
