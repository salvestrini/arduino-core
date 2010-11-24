#include <WProgram.h>

#if 0
#include <Matrix.h>
#include <Ethernet.h>
#include <Client.h>
#include <Server.h>
#include <Udp.h>
#include <Stepper.h>
#include <binary.h>
#include <Sprite.h>
#include <Firmata.h>
#include <Boards.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Servo.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#endif

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
