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

#ifndef E2PROM_H
#define E2PROM_H

#include <stdlib.h>

class E2PROMClass {
 public:
        uint8_t read(size_t address);
        void    write(size_t address, uint8_t value);
        size_t  size();

 private:
        bool isAddressOK(size_t address);
};

extern E2PROMClass E2PROM;

#endif
