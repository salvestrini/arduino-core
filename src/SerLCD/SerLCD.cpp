#include <WProgram.h>

#include <SerLCD.h>

#define COMMAND_CLEAR           0x01
#define COMMAND_MOVE_RIGHT      0x14
#define COMMAND_MOVE_LEFT       0x10
#define COMMAND_SCROLL_RIGHT    0x1C
#define COMMAND_SCROLL_LEFT     0x18
#define COMMAND_DISPLAY_ON      0x0C
#define COMMAND_DISPLAY_OFF     0x08
#define COMMAND_UNDERLINE_ON    0x0E
#define COMMAND_UNDERLINE_OFF   0x0C
#define COMMAND_BLINKING_ON     0x0D
#define COMMAND_BLINKING_OFF    0x0C
#define COMMAND_CURSOR_POSITION 0x80

#define DEFAULT_PAUSE 100
#define PAUSE() do { delay(DEFAULT_PAUSE); } while(0);

SerLCD::SerLCD(uint8_t pin,
               uint8_t columns,
               uint8_t rows,
               long    baudRate) :
        SoftwareSerial(0, pin),
        columns_(columns),
        rows_(rows)
{
	pinMode(pin, OUTPUT);
        begin(baudRate);
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

void SerLCD::clear()
{ sendFE(COMMAND_CLEAR); }

void SerLCD::display(bool status)
{ sendFE(status ? COMMAND_DISPLAY_ON : COMMAND_DISPLAY_OFF); }

void SerLCD::underline(bool status)
{ sendFE(status ? COMMAND_UNDERLINE_ON : COMMAND_UNDERLINE_OFF); }

void SerLCD::blinking(bool status)
{ sendFE(status ? COMMAND_BLINKING_ON : COMMAND_BLINKING_OFF); }

void SerLCD::backlight(uint8_t value)
{
        if (value > 29) {
                value = 29;
        }
        send7C(128 + value);
}

void SerLCD::goTo(int position)
{
        int pos = 128;

        if (position < 16){
                pos += position;
        } else if (position < 32){
                pos += position + 48;
        } else {
                pos += position;
        }

        sendFE(pos);
}

void SerLCD::goTo(uint8_t row,
                  uint8_t column)
{ goTo(row * (rows_ - 1) + column); }

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
