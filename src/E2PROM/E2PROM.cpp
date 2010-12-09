//
// E2PROM - An E2PROM library
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

#include <avr/eeprom.h>
#include "WConstants.h"

#include "E2PROM.h"

#if   (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__))
#define MAX_ADDRESS 4096
#elif (defined(__AVR_ATmega168__)  || defined(__AVR_ATmega8__))
#define MAX_ADDRESS 512
#elif defined(__AVR_ATmega328P__)
#define MAX_ADDRESS 1024
#else
#error Unsupported AVR
#endif

bool E2PROMClass::isAddressOK(size_t address)
{ return ((address < MAX_ADDRESS) ? true : false); }

uint8_t E2PROMClass::read(size_t address)
{
        if (!isAddressOK(address)) {
                return -1; // XXX FIXME: Find something better ...
        }

	return eeprom_read_byte((unsigned char *) address);
}

void E2PROMClass::write(size_t address, uint8_t value)
{
        if (!isAddressOK(address)) {
                return; // XXX FIXME: Find something better ...
        }

	eeprom_write_byte((unsigned char *) address, value);
}

E2PROMClass E2PROM;
