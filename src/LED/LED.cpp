//
// LED - LED convenience library
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
#include "LED.h"

LED::LED(uint8_t pin) :
        pin_(pin),
        state_(false)
{ pinMode(pin_, OUTPUT); }

void LED::on()
{
        digitalWrite(pin_, HIGH);
        state_ = true;
}

void LED::off()
{
        digitalWrite(pin_, LOW);
        state_ = false;
}

void LED::toggle()
{ (void) (state_ ? off() : on()); }
