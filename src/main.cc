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

#define PIN_SER_RX  1
#define PIN_SER_TX  0
#define PIN_LCD     2
#define PIN_LED    13

#define PANIC_LED_SUPPORT 1
#define TEST              7

#include <WProgram.h>

#if PANIC_LED_SUPPORT
#include "LED.h"

LED led(PIN_LED);
#endif

void panic()
{
        for (;;) {
                delay(100);
#if PANIC_LED_SUPPORT
                led.toggle();
#endif
        }
}

extern "C" void __cxa_pure_virtual(void) { panic(); }

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

#if TEST == 0
#include "LED.h"

void setup()
{ }

uint8_t i = 0;

void loop()
{
        led.toggle();
        delay(i++);
}

#endif

#if TEST == 1
#include "SerLCD.h"
#include "Menu.h"

SerLCD LCD = SerLCD(PIN_LCD, SerLCD::TYPE_2x16, SerLCD::BAUD_9600);

// Menu(const String & name,
//      const Menu *   parent,
//      const Menu *   child,
//      const Menu *   sibling);

Menu menu1     = Menu("menu1"  );
Menu menu11    = Menu("menu11" );

Menu menu2     = Menu("menu2"  );
Menu menu21    = Menu("menu21" );
Menu menu22    = Menu("menu22" );
Menu menu23    = Menu("menu23" );

Menu menu3     = Menu("menu3"  );

Menu menu4     = Menu("menu4"  );
Menu menu41    = Menu("menu41" );
Menu menu42    = Menu("menu42" );
Menu menu421   = Menu("menu421");
Menu menu422   = Menu("menu422");

MenuManager mm = MenuManager(&menu1);

void setup()
{
        pinMode(PIN_LCD, OUTPUT);

        menu1.link   (0       , &menu11 , &menu2   , 0       );
        menu11.link  (&menu1  , 0       , 0        , 0       );
        menu2.link   (0       , &menu21 , &menu3   , 0       );
        menu21.link  (&menu2  , 0       , &menu22  , 0       );
        menu22.link  (&menu2  , 0       , &menu23  , &menu21 );
        menu23.link  (&menu2  , 0       , 0        , &menu22 );
        menu3.link   (0       , 0       , &menu4   , 0       );
        menu4.link   (0       , &menu41 , 0        , 0       );
        menu41.link  (&menu4  , 0       , &menu42  , 0       );
        menu42.link  (&menu4  , &menu421, 0        , &menu41 );
        menu421.link (&menu42 , 0       , &menu422 , 0       );
        menu422.link (&menu42 , 0       , 0        , &menu421);

        LCD.backlight(15);
        LCD.clear();

        LCD.blinking(true);
        LCD.underline(true);
}

int i = 0;

void loop()
{
        mm.sendEvent(MenuManager::EVENT_MOVE_SIBLING_NEXT);
        delay(100);
        mm.sendEvent(MenuManager::EVENT_MOVE_SIBLING_PREVIOUS);
        delay(100);
        mm.sendEvent(MenuManager::EVENT_MOVE_NEXT);
        delay(100);
        mm.sendEvent(MenuManager::EVENT_MOVE_PREVIOUS);
        delay(100);
        mm.sendEvent(MenuManager::EVENT_SELECT);
        delay(100);

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

        delay(100);
}

#endif

#if TEST == 2
#include <SoftwareSerial.h>

SoftwareSerial LCD = SoftwareSerial(0, PIN_LDC_TX);

void setup()
{
        pinMode(PIN_LCD, OUTPUT);

        LCD.begin(9600);

        LCD.print(0xFE, BYTE);   // command flag
        LCD.print(0x01, BYTE);   // clear command.
        LCD.print(0x7C, BYTE);   // command flag for backlight stuff
        LCD.print(143,  BYTE);   // light level

}

int i = 0;

void loop()
{
        LCD.print(0xFE, BYTE);   // command flag
        LCD.print(0x01, BYTE);   // clear command
        delay(100);

        LCD.print(i++);
        delay(1000);
}

#endif

#if TEST == 3
//#include "sd_raw.h"

void setup()
{
        Serial.begin(9600);

        Serial.print("Initializing SD card ...\n");

//        if (sd_raw_init() == 0) {
//                Serial.print("Cannot initialize SD card\n");
//                panic();
//        }
}

int i = 0;

void loop()
{
        Serial.print("Loop #");
        Serial.print(i++);
        Serial.print("\n");

        delay(1000);

//        struct sd_raw_info info;
//
//        if (sd_raw_get_info(&info)) {
//                Serial.print("SD card information:\n");
//                Serial.print("  Manufacturer = ");
//                Serial.print(info.manufacturer);
//                Serial.print("\n");
//
//                Serial.print("  OEM          = ");
//                Serial.print(info.oem[2]);
//                Serial.print(info.oem[1]);
//                Serial.print(info.oem[0]);
//                Serial.print("\n");
//
//                Serial.print("  Product      = ");
//                Serial.print(info.product[5]);
//                Serial.print(info.product[4]);
//                Serial.print(info.product[3]);
//                Serial.print(info.product[2]);
//                Serial.print(info.product[1]);
//                Serial.print(info.product[0]);
//                Serial.print("\n");
//
//                Serial.print("  Manufactured = ");
//                Serial.print(info.manufacturing_month);
//                Serial.print("/");
//                Serial.print(2000 + info.manufacturing_year);
//                Serial.print("\n");
//
//                Serial.print("  Copied       = ");
//                Serial.print(info.flag_copy ? "yes" : "no");
//                Serial.print("\n");
//
//                Serial.print("  Write prot.  = ");
//                Serial.print(info.flag_write_protect ? "yes" : "no");
//                Serial.print("\n");
//
//                Serial.print("  Format       = ");
//                Serial.print(info.format);
//                Serial.print("\n");
//
//        } else {
//                Serial.print("Cannot read card information\n");
//        }
}

#endif

#if TEST == 4
void setup()
{
        Serial.begin(9600);
}

int row = 0;

void loop()
{
        if ((row % 20) == 0) {
                Serial.print('\n');
                Serial.print('\r');
        }
        Serial.print('#');
        delay(100);
        row++;
}
#endif

#if TEST == 5
#include "Console.h"

Console console; //(PIN_SER_RX, PIN_SER_TX);

void setup()
{ }

void loop()
{
        console.run();
        //        delay(100);
        led.toggle();
}
#endif

#if TEST == 6
#include <SdFat.h>
//#include <SdFatUtil.h>

Sd2Card  card;
SdVolume volume;
//SdFile   root;
//SdFile   file;

#define error(s) error_P(s)

void error(const char * str) {
        Serial.print("error: ");
        Serial.println(str);
 
       if (card.errorCode()) {
                Serial.print("SD error: ");
                Serial.print(card.errorCode(), HEX);
                Serial.print(',');
                Serial.println(card.errorData(), HEX);
        }

        panic();
}

void setup(void) {
        Serial.begin(9600);

#if 0
        Serial.println();
        Serial.println("type any character to start");
        while (!Serial.available());
        Serial.println();
#endif

        // initialize the SD card at SPI_HALF_SPEED to avoid bus errors with
        // breadboards.  use SPI_FULL_SPEED for better performance.
        if (!card.init(SPI_HALF_SPEED)) error("card.init failed");

        // initialize a FAT volume
        if (!volume.init(&card)) error("volume.init failed");

//  // open the root directory
//  if (!root.openRoot(&volume)) error("openRoot failed");
//
//  // open a file
//  if (file.open(&root, "PRINT00.TXT", O_READ)) {
//          //Serial.println("Opened PRINT00.TXT");
//  }
//  else if (file.open(&root, "WRITE00.TXT", O_READ)) {
//          //Serial.println("Opened WRITE00.TXT");
//  }
//  else{
//          //error("file.open failed");
//  }
//  //Serial.println();
//
//#if 0  
//  // copy file to serial port
//  int16_t n;
//  uint8_t buf[7];// nothing special about 7, just a lucky number.
//  while ((n = file.read(buf, sizeof(buf))) > 0) {
//    for (uint8_t i = 0; i < n; i++) Serial.print(buf[i]);
//  }
//  /* easier way
//  int16_t c;
//  while ((c = file.read()) > 0) Serial.print((char)c);
//  */
//  Serial.println("\nDone");
//#endif
}

void loop(void)
{
        panic();
}
#endif

#if TEST == 7
/*
 * List files in root directory.
 */
#include <Fat16.h>
#include <Fat16util.h>

SdCard card;

// store error strings in flash to save RAM
#define error(s) error_P(PSTR(s))

void error_P(const char* str) {
  PgmPrint("error: ");
  SerialPrintln_P(str);
  if (card.errorCode) {
    PgmPrint("SD error: ");
    Serial.println(card.errorCode, HEX);
  }
  while(1);
}

void setup() {
  Serial.begin(9600);
  PgmPrintln("Type any character to start");
  while (!Serial.available());
  
  PgmPrint("Free RAM: ");
  Serial.println(FreeRam());  
 
  if (!card.init()) error("card.init failed!");
  
  if (!Fat16::init(&card)) error("Fat16::init failed!");
  
  Serial.println();
  
  PgmPrintln("Name          Modify Date/Time    Size");
  
  Fat16::ls(LS_DATE | LS_SIZE);
}

void loop()
{
        panic();
}
#endif

#if TEST > 7
#error Undefined test
#endif
