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

#ifndef GSM_H
#define GSM_H

#include <AFSoftSerial.h>

#define GSM_RX_PIN      0
#define GSM_TX_PIN      1
#define GSM_RATE        9600
#define GSM_BUFFER_SIZE 90

class GSM : private AFSoftSerial {
 public:
        GSM(uint8_t rx_pin = GSM_RX_PIN,
            uint8_t tx_pin = GSM_TX_PIN,
            long    rate   = GSM_RATE);
        ~GSM();

        bool send(const char number[],
                  const char message[]);

 private:
        bool isOK();
        bool waitForOK();
        void readline();

        char buffer_[GSM_BUFFER_SIZE];
};

#endif
