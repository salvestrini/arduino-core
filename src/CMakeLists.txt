message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}")

#
# Core libraries
#
include_directories(${ArduinoCode_SOURCE_DIR}/libs/core)
link_directories(${ArduinoCode_BINARY_DIR}/libs/core)

#
# External libraries
#
include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/Matrix)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/Matrix)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/Ethernet)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/Ethernet)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/Stepper)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/Stepper)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/Sprite)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/Sprite)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/Firmata)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/Firmata)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/LiquidCrystal)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/LiquidCrystal)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/Wire)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/Wire)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/EEPROM)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/EEPROM)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/Servo)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/Servo)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/SPI)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/SPI)

include_directories(${ArduinoCode_SOURCE_DIR}/libs/libraries/SoftwareSerial)
link_directories(${ArduinoCode_BINARY_DIR}/libs/libraries/SoftwareSerial)

#
# Our libraries
#
add_subdirectory(SerLCD)
include_directories(${ArduinoCode_SOURCE_DIR}/src/SerLCD)
link_directories(${ArduinoCode_BINARY_DIR}/src/SerLCD)

add_subdirectory(Menu)
include_directories(${ArduinoCode_SOURCE_DIR}/src/Menu)
link_directories(${ArduinoCode_BINARY_DIR}/src/Menu)

add_subdirectory(microSD)
include_directories(${ArduinoCode_SOURCE_DIR}/src/microSD)
link_directories(${ArduinoCode_BINARY_DIR}/src/microSD)

add_subdirectory(LED)
include_directories(${ArduinoCode_SOURCE_DIR}/src/LED)
link_directories(${ArduinoCode_BINARY_DIR}/src/LED)

#
# Executable
#
add_executable(image
  main.cc
  )

target_link_libraries(image
  SerLCD
  Menu
  microSD
  LED

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

  core
  )
