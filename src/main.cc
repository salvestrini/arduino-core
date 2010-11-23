#include "WProgram.h"

extern "C" void __cxa_pure_virtual(void)
{
        Serial.print(__PRETTY_FUNCTION__);
        Serial.println(" called");

	for(;;) {
                delay(1000);
	}
}

void setup()
{
	Serial.begin(9600);

	pinMode(13, OUTPUT);

}

void loop()
{
        Serial.println("Hello");
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
}
