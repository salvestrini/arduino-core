//
// Morse - A Morse convenience library
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

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Morse.h"

// http://en.wikipedia.org/wiki/Morse_code

const struct Morse::code Morse::codes_[] = {
        { 'A', ".- "   }, { 'B', "-... " }, { 'C', "-.-. " }, { 'D', "-.. "  },
        { 'E', ". "    }, { 'F', "..-. " }, { 'G', "--. "  }, { 'H', ".... " },
        { 'I', ".. "   }, { 'J', ".--- " }, { 'K', ".-.- " }, { 'L', ".-.. " },
        { 'M', "-- "   }, { 'N', "-. "   }, { 'O', "--- "  }, { 'P', ".--. " },
        { 'Q', "--.- " }, { 'R', ".-. "  }, { 'S', "... "  }, { 'T', "- "    },
        { 'U', "..- "  }, { 'V', "...- " }, { 'W', ".-- "  }, { 'X', "-..- " },
        { 'Y', "-.-- " }, { 'Z', "--.. " }, { ' ', " "     },
};

void Morse::write(const char message[],
                  void       (* dash)(),
                  void       (* dot)())
{
        // Silently discard unknown characters in msg

        for (size_t i = 0; message[i]; ++i) {
                char c = toupper(message[i]);

                for (size_t j = 0; j < sizeof codes_ / sizeof *codes_; ++j) {
                        if (c != codes_[j].letter) {
                                continue;
                        }

                        for (size_t k = 0; k < strlen(codes_[j].morse); k++) {
                                if (codes_[j].morse[k] == '.') {
                                        dot();
                                } else {
                                        dash();
                                }
                        }

                        break;
                }
        }
}
