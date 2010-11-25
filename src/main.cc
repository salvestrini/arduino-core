//
// Copyright (c) 2010 Francesco Salvestrini.  All right reserved.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#define PIN_TX 2
#define TEST   1

#include <WProgram.h>

#if TEST

#include "SerLCD.h"

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

SerLCD LCD = SerLCD(PIN_TX, SerLCD::TYPE_2x16, SerLCD::BAUD_9600);

void setup()
{
        pinMode(PIN_TX, OUTPUT);

        LCD.backlight(15);
        LCD.clear();

        LCD.goTo(0, 0);
        LCD.print("CIAO");
        LCD.goTo(1, 8);
        LCD.print("MONDO");

        LCD.blinking(true);
        LCD.underline(true);
}

int i = 0;

void loop()
{
#if 0
        LCD.goTo(0, 0);
        LCD.print("i=");
        LCD.print(i);

        LCD.goTo(1, 0);
        LCD.print("j=");
        LCD.print(i * 2);

        LCD.goTo(0, 8);
        LCD.print("k=");
        LCD.print(i * 4);

        LCD.goTo(1, 8);
        LCD.print("l=");
        LCD.print(i * 8);

        i++;
#endif

        delay(100);
}

#else

#include <SoftwareSerial.h>

SoftwareSerial LCD = SoftwareSerial(0, txPin);

void setup()
{
        pinMode(PIN_TX, OUTPUT);

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
