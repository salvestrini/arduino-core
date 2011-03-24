message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

#
# Core libraries
#
include_directories(${ArduinoCode_SOURCE_DIR}/libs/Core)
link_directories(${ArduinoCode_BINARY_DIR}/libs/Core)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/SD)
link_directories(${ArduinoCode_BINARY_DIR}/libs/SD)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/Matrix)
link_directories(${ArduinoCode_BINARY_DIR}/libs/Matrix)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/Ethernet)
link_directories(${ArduinoCode_BINARY_DIR}/libs/Ethernet)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/Stepper)
link_directories(${ArduinoCode_BINARY_DIR}/libs/Stepper)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/Sprite)
link_directories(${ArduinoCode_BINARY_DIR}/libs/Sprite)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/Firmata)
link_directories(${ArduinoCode_BINARY_DIR}/libs/Firmata)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/LiquidCrystal)
link_directories(${ArduinoCode_BINARY_DIR}/libs/LiquidCrystal)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/Wire)
link_directories(${ArduinoCode_BINARY_DIR}/libs/Wire)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/EEPROM)
link_directories(${ArduinoCode_BINARY_DIR}/libs/EEPROM)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/Servo)
link_directories(${ArduinoCode_BINARY_DIR}/libs/Servo)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/SPI)
link_directories(${ArduinoCode_BINARY_DIR}/libs/SPI)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/SoftwareSerial)
link_directories(${ArduinoCode_BINARY_DIR}/libs/SoftwareSerial)

#
# Third parties
#
add_subdirectory(SdFat)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SdFat)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/SdFat)

add_subdirectory(Fat16)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Fat16)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/Fat16)

add_subdirectory(FAT16)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/FAT16)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/FAT16)

#add_subdirectory(NewSoftSerial)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/NewSoftSerial)
#link_directories(${CMAKE_CURRENT_BINARY_DIR}/NewSoftSerial)

add_subdirectory(AFSoftSerial)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/AFSoftSerial)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/AFSoftSerial)

#
# Our libraries
#
add_subdirectory(SerLCD)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SerLCD)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/SerLCD)

add_subdirectory(Menu)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Menu)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/Menu)

add_subdirectory(LED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/LED)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/LED)

add_subdirectory(Console)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Console)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/Console)

add_subdirectory(GSM)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/GSM)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/GSM)

add_subdirectory(E2PROM)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/E2PROM)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/E2PROM)

add_subdirectory(Morse)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Morse)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/Morse)

#
# Executable
#
add_executable(image
  main.cc
  )

target_link_libraries(image
  SerLCD
  Menu
  LED
  Console
  GSM
  E2PROM
  Morse

#  NewSoftSerial
  AFSoftSerial
  SdFat
  Fat16
  FAT16

  Matrix
  Ethernet
  Stepper
  Sprite
  Firmata
  LiquidCrystal
  Wire
  EEPROM
  Servo
  SPI
  SoftwareSerial

  Core
  )
