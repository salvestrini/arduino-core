#include "WProgram.h"

//after build -- to flash
//avr-objcopy -O ihex -R .eeprom blink.out blink.hex
//sudo avrdude -V -c dragon_isp -p m168 -b 19200 -P usb -U flash:w:cmaketest.hex

extern "C" void __cxa_pure_virtual(void)
{
	for(;;) {
                Serial.println(__PRETTY_FUNCTION__);
	}
}

int main()
{
	init();

	Serial.begin(9600);

	pinMode(13, OUTPUT);

	for(;;) {
		Serial.println("Hello");
		digitalWrite(13, HIGH);
		delay(1000);
		digitalWrite(13, LOW);
	}

	return 0;
}
