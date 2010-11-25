//
// SerLCD - Sparkfun SerLCD library
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

#include <SerLCD.h>
#include <WProgram.h>

#define CMD_CLEAR           0x01

#define CMD_ROWS_2          0x06
#define CMD_ROWS_4          0x05
#define CMD_COLS_16         0x04
#define CMD_COLS_20         0x03

#define CMD_DISPLAY_OFF     0x08
#define CMD_DISPLAY_ON      0x0C

#define CMD_TOGGLE_SPLASH   0x09

#define CMD_MOVE_LEFT       0x10
#define CMD_MOVE_RIGHT      0x14

#define CMD_SCROLL_LEFT     0x18
#define CMD_SCROLL_RIGHT    0x1C

#define CMD_UNDERLINE_ON    0x0E
#define CMD_UNDERLINE_OFF   0x0C
#define CMD_BLINKING_ON     0x0D
#define CMD_BLINKING_OFF    0x0C

#define CMD_CURSOR_POSITION 0x80

#define CMD_SAVE_SPLASH     'j'

#define CMD_RATE_2400       'k'
#define CMD_RATE_4800       'l'
#define CMD_RATE_9600       'm'
#define CMD_RATE_14400      'n'
#define CMD_RATE_19200      'o'
#define CMD_RATE_38400      'p'

#define CMD_RESET           'r'

// PAUSE() has to be replaced with an 80 char buffer
#define DEFAULT_PAUSE 100
#define PAUSE() do { delay(DEFAULT_PAUSE); } while(0);

SerLCD::SerLCD(uint8_t     pin,
               SerLCD_type type,
               SerLCD_rate rate) :
        SoftwareSerial(0, pin),
        type_(type),
        rate_(rate)
{
        switch (type_) {
                case TYPE_4x20: rows_ = 4, columns_ = 20; break;
                case TYPE_4x16: rows_ = 4, columns_ = 16; break;
                case TYPE_2x20: rows_ = 2, columns_ = 20; break;
                case TYPE_2x16: rows_ = 2, columns_ = 16; break;
        }

        pinMode(pin, OUTPUT);

        // Set the port rate to the safe value
        begin(9600);

#if 0
        // Reset the LCD (at 9600 bauds)
        reset();

        // Set the LCD baudrate while the splash is showing
        setRate(rate);

        // Now change the port rate to its final value
        long baud;
        switch (rate) {
                BAUD_2400:  baud = 2400;  break;
                BAUD_4800:  baud = 4800;  break;
                BAUD_9600:  baud = 9600;  break;
                BAUD_14400: baud = 14400; break;
                BAUD_19200: baud = 19200; break;
                BAUD_38400: baud = 38400; break;
        }
        begin(baud);

        // We should communicate cleanly now, set the LCD type then
        setType(type_);

        // Clean the screen from trash
        clear();
#endif
}

SerLCD::~SerLCD()
{ }

void SerLCD::sendFE(uint8_t value)
{
        PAUSE();
        SoftwareSerial::print(0xFE,  BYTE);
        SoftwareSerial::print(value, BYTE);
}

void SerLCD::send7C(uint8_t value)
{
        PAUSE();
        SoftwareSerial::print(0x7C,  BYTE);
        SoftwareSerial::print(value, BYTE);
}

void SerLCD::sendFExN(uint8_t value, uint8_t count)
{
        for (uint8_t i = 0; i < count; i++) {
                sendFE(value);
        }
}

void SerLCD::send7CxN(uint8_t value, uint8_t count)
{
        for (uint8_t i = 0; i < count; i++) {
                send7C(value);
        }
}

void SerLCD::reset()
{ send7C(CMD_RESET); }

void SerLCD::setRate(SerLCD_rate rate)
{
        switch (rate) {
                BAUD_2400:  send7C(CMD_RATE_2400);  break;
                BAUD_4800:  send7C(CMD_RATE_4800);  break;
                BAUD_9600:  send7C(CMD_RATE_9600);  break;
                BAUD_14400: send7C(CMD_RATE_14400); break;
                BAUD_19200: send7C(CMD_RATE_19200); break;
                BAUD_38400: send7C(CMD_RATE_38400); break;
        }
}

void SerLCD::setType(SerLCD_type type)
{
        switch (type) {
                case TYPE_4x20: send7C(CMD_COLS_20); send7C(CMD_ROWS_4); break;
                case TYPE_4x16: send7C(CMD_COLS_16); send7C(CMD_ROWS_4); break;
                case TYPE_2x20: send7C(CMD_COLS_20); send7C(CMD_ROWS_2); break;
                case TYPE_2x16: send7C(CMD_COLS_16); send7C(CMD_ROWS_2); break;
        }
}

void SerLCD::toggleSplash()
{ send7C(CMD_TOGGLE_SPLASH); }

void SerLCD::saveAsSplash()
{ sendFE(CMD_SAVE_SPLASH); }

void SerLCD::clear()
{ sendFE(CMD_CLEAR); }

void SerLCD::display(bool status)
{ sendFE(status ? CMD_DISPLAY_ON : CMD_DISPLAY_OFF); }

void SerLCD::underline(bool status)
{ sendFE(status ? CMD_UNDERLINE_ON : CMD_UNDERLINE_OFF); }

void SerLCD::blinking(bool status)
{ sendFE(status ? CMD_BLINKING_ON : CMD_BLINKING_OFF); }

void SerLCD::backlight(uint8_t value)
{
        if (value > 29) {
                value = 29;
        }

        send7C(128 + value);
}

void SerLCD::moveCursorLeft(uint8_t count)
{ sendFExN(CMD_MOVE_LEFT, count); }

void SerLCD::moveCursorRight(uint8_t count)
{ sendFExN(CMD_MOVE_RIGHT, count); }

void SerLCD::scrollLineLeft(uint8_t count)
{ sendFExN(CMD_SCROLL_LEFT, count); }

void SerLCD::scrollLineRight(uint8_t count)
{ sendFExN(CMD_SCROLL_RIGHT, count); }

void SerLCD::goTo(uint8_t row,
                  uint8_t column)
{
        uint8_t position;

        if (row > rows_ - 1) {
                row = rows_ - 1;
        }

        if (column > columns_ - 1) {
                column = columns_ - 1;
        }

        if (row == 0) {
                position = 0;
        } else if (row == 1) {
                position = 64;
        } else if (row == 2) {
                switch (type_) {
                        case TYPE_2x16:
                        case TYPE_4x16:
                                position = 16;
                                break;
                        case TYPE_2x20:
                        case TYPE_4x20:
                                position = 20;
                                break;
                }
        } else if (row == 3) {
                switch (type_) {
                        case TYPE_2x16:
                        case TYPE_4x16:
                                position = 80;
                                break;
                        case TYPE_2x20:
                        case TYPE_4x20:
                                position = 84;
                                break;
                }
        } else {
                // Unhandled
                return;
        }

        position += column;
        position |= 0x80;

        sendFE(position);
}

void SerLCD::print(char p)
{ PAUSE(); SoftwareSerial::print(p); }

void SerLCD::print(const char p[])
{ PAUSE(); SoftwareSerial::print(p); }

void SerLCD::print(uint8_t p)
{ PAUSE(); SoftwareSerial::print(p); }

void SerLCD::print(int p)
{ PAUSE(); SoftwareSerial::print(p); }

void SerLCD::print(unsigned int p)
{ PAUSE(); SoftwareSerial::print(p); }

void SerLCD::print(long p)
{ PAUSE(); SoftwareSerial::print(p); }

void SerLCD::print(unsigned long p)
{ PAUSE(); SoftwareSerial::print(p); }

#if 0
void SerLCD::println(void)
{ PAUSE(); SoftwareSerial::println(); }

void SerLCD::println(char p)
{ PAUSE(); SoftwareSerial::println(p); }

void SerLCD::println(const char p[])
{ PAUSE(); SoftwareSerial::println(p); }

void SerLCD::println(uint8_t p)
{ PAUSE(); SoftwareSerial::println(p);}

void SerLCD::println(int p)
{ PAUSE(); SoftwareSerial::println(p); }

void SerLCD::println(long p)
{ PAUSE(); SoftwareSerial::println(p);}

void SerLCD::println(unsigned long p)
{ PAUSE(); SoftwareSerial::println(p); }
#endif

// To define graphical characters send the command 0xfe-0x40 and then from 1
// to 8 sequences of 8 bytes containing the bitmaps (for example 0x15-0x0a-
// 0x15-0x0a-0x15-0x0a-0x15-0x0a will define a 5x8 checkered pattern) and
// finally a 0xfe-0x01 (clear screen ending bitmap definition mode).
//
// Characters are stored in CG-RAM of the display; this means that they will
// have to be redefined on every reboot.
