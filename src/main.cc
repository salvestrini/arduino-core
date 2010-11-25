#define TEST 1

#include <WProgram.h>

#if TEST

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
	for(;;) {
                delay(1000);
	}
}

#include "SerLCD.h"

SerLCD LCD = SerLCD(2, 16, 2, 9600);

void setup()
{
        pinMode(13, OUTPUT);

        LCD.backlight(15);
        LCD.blinking(true);
        LCD.display(true);
        LCD.clear();
}

int i = 0;

void loop()
{
        LCD.goTo(0, 0);
        LCD.print("i=");
        LCD.print(i);
        LCD.goTo(1, 0);
        LCD.print("j=");
        LCD.print(i * 2);
        i++;
#if 0
        digitalWrite(13, HIGH);
        delay(100);
        digitalWrite(13, LOW);
        delay(100);
#endif
}

#else

#include <SoftwareSerial.h>

#define txPin 2

SoftwareSerial LCD = SoftwareSerial(0, txPin);
// since the LCD does not send data back to the Arduino, we should only define the txPin

void setup()
{
        pinMode(txPin, OUTPUT);
        LCD.begin(9600);
        LCD.print(0xFE, BYTE);   //command flag
        LCD.print(0x01, BYTE);   //clear command.
        LCD.print(0x7C, BYTE);   //command flag for backlight stuff
        LCD.print(143,  BYTE);   //light level.

}

int i = 0;

void loop()
{
        LCD.print(0xFE, BYTE);   //command flag
        LCD.print(0x01, BYTE);   //clear command.
        delay(100);
        LCD.print(i++);
        delay(1000);
}

#endif
