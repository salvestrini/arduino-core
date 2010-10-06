include_directories(${ArduinoCode_SOURCE_DIR}/libs/core)

link_directories(${ArduinoCode_SOURCE_DIR}/libs/core)

add_executable(image
  main.cc)

target_link_libraries(image core)
