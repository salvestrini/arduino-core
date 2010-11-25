#ifndef SERLCD_H
#define SERLCD_H

#include <SoftwareSerial.h>

class SerLCD : private SoftwareSerial {
 public:
        SerLCD(uint8_t pin,
               uint8_t columns  = 16,
               uint8_t rows     = 2,
               long    baudRate = 9600);
        ~SerLCD();

        void print(char);
        void print(const char[]);
        void print(uint8_t);
        void print(int);
        void print(unsigned int);
        void print(long);
        void print(unsigned long);

        void println(void);
        void println(char);
        void println(const char[]);
        void println(uint8_t);
        void println(int);
        void println(long);
        void println(unsigned long);

        void clear();
        void goTo(uint8_t row,
                  uint8_t column);

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

 private:
        uint8_t columns_;
        uint8_t rows_;

        void goTo(int position);

        void sendFE(uint8_t value);
        void send7C(uint8_t value);
};

#endif
