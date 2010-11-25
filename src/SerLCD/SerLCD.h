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

#ifndef SERLCD_H
#define SERLCD_H

#include <SoftwareSerial.h>

class SerLCD : private SoftwareSerial {
 public:
        enum SerLCD_type {
                TYPE_2x16,
                TYPE_2x20,
                TYPE_4x16,
                TYPE_4x20
        };

        enum SerLCD_rate {
                BAUD_2400,
                BAUD_4800,
                BAUD_9600,
                BAUD_14400,
                BAUD_19200,
                BAUD_38400
        };

        SerLCD(uint8_t     pin,
               SerLCD_type type   = TYPE_2x16,
               SerLCD_rate rate   = BAUD_9600);
        ~SerLCD();

        void print(char);
        void print(const char[]);
        void print(uint8_t);
        void print(int);
        void print(unsigned int);
        void print(long);
        void print(unsigned long);

#if 0
        void println(void);
        void println(char);
        void println(const char[]);
        void println(uint8_t);
        void println(int);
        void println(long);
        void println(unsigned long);
#endif

        void clear();

        void goTo(uint8_t row,
                  uint8_t column);
        void moveCursorLeft(uint8_t count  = 1);
        void moveCursorRight(uint8_t count = 1);
        void scrollLineLeft(uint8_t count  = 1);
        void scrollLineRight(uint8_t count = 1);

        void backlight(uint8_t value); // 0 .. 29
        void backlightOn()  { backlight(29); }
        void backlightOff() { backlight(0);  }

        void display(bool status);
        void displayOn()  { display(true); }
        void displayOff() { display(false); }

        void underline(bool status);
        void underlineOn()  { underline(true); }
        void underlineOff() { underline(false); }

        void blinking(bool status);
        void blinkingOn()  { blinking(true); }
        void blinkingOff() { blinking(false); }

        void toggleSplash();
        void saveAsSplash();

 private:
        uint8_t     columns_;
        uint8_t     rows_;
        SerLCD_type type_;
        SerLCD_rate rate_;

        void sendFE(uint8_t value);
        void send7C(uint8_t value);

        void sendFExN(uint8_t value, uint8_t count);
        void send7CxN(uint8_t value, uint8_t count);

        void setRate(SerLCD_rate rate);

        // Set LCD EEPROM: a power-cycle is needed afterwards
        void setType(SerLCD_type type);

        // Convenience command: issue it (at 9600) while the splash-screen
        // is showing
        void reset();
};

#endif
