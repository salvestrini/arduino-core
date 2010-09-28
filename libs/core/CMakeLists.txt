include(${ArduinoCode_SOURCE_DIR}/cmake/arduino_diecimila_crosscompile.cmake)

add_library(arduinocore
	HardwareSerial.cpp
	Print.cpp
	Tone.cpp
	WInterrupts.c
	WMath.cpp
	WString.cpp
	main.cpp
	pins_arduino.c
	wiring.c
	wiring_analog.c
	wiring_digital.c
	wiring_pulse.c
	wiring_shift.c
)
