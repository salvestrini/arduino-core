//
// GSM - A GSM library
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
#include "GSM.h"

#define GSM_CMD_SET_SMS_TXT_MODE "AT+CMGF=1" 
#define GSM_CMD_SEND_MSG         "AT+CMGS=" 

#define DELAY_AFTER_COMMAND 500

GSM::GSM(uint8_t rx_pin,
         uint8_t tx_pin,
         long    rate) :
        AFSoftSerial(rx_pin, tx_pin)
{
        pinMode(rx_pin, INPUT);
        pinMode(tx_pin, OUTPUT);
        begin(rate);
        delay(DELAY_AFTER_COMMAND);
}

GSM::~GSM()
{ }

void GSM::readline(void) {
        size_t i = 0;

        while (true) {
                char c = read();
                if (c == -1) {
                        continue;
                }

                if (c == '\n') {
                        continue;
                }

                if ((i == (GSM_BUFFER_SIZE - 1)) || (c == '\r')) {
                        buffer_[i] = 0;
                        return;
                }

                buffer_[i]= c;
        }
}

bool GSM::waitForOK()
{
        while (available()) {
                readline();

                if (strncmp(buffer_, "OK", 2) == 0) {
                        return true;
                }
        }

        return false;
}

bool GSM::isOK()
{
        println("AT");
        delay(DELAY_AFTER_COMMAND);
        return waitForOK();
}

bool GSM::send(const char number[],
               const char message[])
{
        println(GSM_CMD_SET_SMS_TXT_MODE);
        delay(DELAY_AFTER_COMMAND);

        print(GSM_CMD_SEND_MSG);
        print("\"");
        print(number);
        print("\"");
        println();
        delay(DELAY_AFTER_COMMAND);

        print(message);
        println(26, BYTE); // CTRL+Z
        delay(DELAY_AFTER_COMMAND);

        return isOK();
}
