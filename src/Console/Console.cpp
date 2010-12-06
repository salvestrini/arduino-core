//
// Console - A console library
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

#include <WProgram.h>
#include "Console.h"

//Console::Console(uint8_t rx_pin,
//                 uint8_t tx_pin,
//                 long    rate,
//                 bool    echo) :
//        AFSoftSerial(rx_pin, tx_pin),
//        echo_(echo)
//{
//        pinMode(rx_pin, INPUT);
//        pinMode(tx_pin, OUTPUT);
//
//        begin(rate);
//}

Console::Console(long rate,
                 bool echo) :
        echo_(echo)
{
        Serial.begin(rate);
}

Console::~Console()
{ }

void Console::run()
{
        Serial.write('.');

        if (Serial.available()) {
                int c = Serial.read();
                if (c != -1) {
                        if (echo_) {
                                Serial.write(static_cast<uint8_t>(c));
                        }
                }
        }
}
