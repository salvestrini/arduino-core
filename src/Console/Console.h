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

#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdint.h>
#include <SoftwareSerial.h>

#define CONSOLE_RX_PIN 0
#define CONSOLE_TX_PIN 1
#define CONSOLE_RATE   9600

class Console : private SoftwareSerial {
 public:
        Console(uint8_t rx_pin = CONSOLE_RX_PIN,
                uint8_t tx_pin = CONSOLE_TX_PIN,
                long    rate   = CONSOLE_RATE,
                bool    echo   = true);
        ~Console();

        void run();

 private:
        bool echo_;
};

#endif
