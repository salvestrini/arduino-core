//
// Menu - A menu library
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

#ifndef MENU_H
#define MENU_H

#include "WString.h"

class Menu {
 public:

        typedef void (* callback)(void);

        Menu(const String & name);
        ~Menu();

        void         link(Menu * parent,
                          Menu * child,
                          Menu * sibling_next,
                          Menu * sibling_previous);
#if 0
        void         link(Menu *   parent,
                          Menu *   sibling_next,
                          Menu *   sibling_previous,
                          callback cb);
#endif
        void         unlink();

        void         select() const;

        const Menu * parent()           const;
        const Menu * child()            const;
        const Menu * sibling_next()     const;
        const Menu * sibling_previous() const;

        const String & name() const;

 private:
        String   name_;

        Menu *   parent_;
        Menu *   child_;
        Menu *   sibling_next_;
        Menu *   sibling_previous_;

        void     set_parent(Menu * m);
        void     set_child(Menu * m);
        void     set_sibling_previous(Menu * m);
        void     set_sibling_next(Menu * m);

        callback cb_;
};

class MenuManager {
 public:
        MenuManager(const Menu * root = 0);
        ~MenuManager();

        enum event {
                EVENT_MOVE_PREVIOUS,
                EVENT_MOVE_NEXT,
                EVENT_MOVE_SIBLING_PREVIOUS,
                EVENT_MOVE_SIBLING_NEXT,
                EVENT_SELECT
        };

        void setCurrent(const Menu * m);
        void sendEvent(const event e);

        void draw();

 private:
        const Menu * current_;
};

#endif
