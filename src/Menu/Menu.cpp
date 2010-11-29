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

#include <WString.h>
#include "Menu.h"

//
// Menu
//


Menu::Menu(const String & name) :
        name_(name),
        parent_(0),
        child_(0),
        sibling_next_(0),
        sibling_previous_(0),
        cb_(0)
{ }

void Menu::set_sibling_previous(Menu * m)
{
        sibling_previous_ = m;
        if (sibling_previous_) {
                sibling_previous_->set_sibling_next(this);
        }
}

void Menu::set_sibling_next(Menu * m)
{
        sibling_next_ = m;
        if (sibling_next_) {
                sibling_next_->set_sibling_previous(this);
        }
}

void Menu::set_parent(Menu * m)
{
        parent_ = m;
        if (parent_) {
                parent_->set_child(this);
        }
}

void Menu::set_child(Menu * m)
{
        child_ = m;
        if (child_) {
                child_->set_parent(this);
        }
}

void Menu::link(Menu * parent,
                Menu * child,
                Menu * sibling_next,
                Menu * sibling_previous)
{
        set_parent(parent);
        set_child(child);
        set_sibling_next(sibling_next);
        set_sibling_previous(sibling_previous);
        cb_ = 0;
}

#if 0
void Menu::link(Menu *   parent,
                Menu *   sibling_next,
                Menu *   sibling_previous,
                callback cb)
{
        set_parent(parent);
        set_child(0);
        set_sibling_next(sibling_next);
        set_sibling_previous(sibling_previous);
        cb_ = cb;
}
#endif

void Menu::unlink()
{ link(0, 0, 0, 0); }

const String & Menu::name() const
{ return name_; }

Menu::~Menu()
{ }

void Menu::select() const
{
        if (cb_) {
                cb_();
        }
}

const Menu * Menu::parent() const
{ return parent_; }

const Menu * Menu::child() const
{ return child_; }

const Menu * Menu::sibling_previous() const
{ return sibling_previous_; }

const Menu * Menu::sibling_next() const
{ return sibling_next_; }

//
// MenuManager
//

MenuManager::MenuManager(const Menu * root) :
        current_(root)
{ }

MenuManager::~MenuManager()
{ }

void MenuManager::setCurrent(const Menu * m)
{ current_ = m; }

void MenuManager::sendEvent(const event e)
{
        if (!current_) {
                return;
        }

        switch (e) {
                case EVENT_MOVE_PREVIOUS:
                        current_ = current_->parent();
                        break;

                case EVENT_MOVE_NEXT:
                        current_ = current_->child();
                        break;

                case EVENT_SELECT:
                        current_->select();
                        break;

                case EVENT_MOVE_SIBLING_PREVIOUS:
                        current_ = current_->sibling_previous();
                        break;

                case EVENT_MOVE_SIBLING_NEXT:
                        current_ = current_->sibling_next();
                        break;
                default:
                        // Nothing to do here ...
                        break;
        }
}

void MenuManager::draw()
{
//        if (current_) {
//                const String & name = current_->name();
//        }
}
