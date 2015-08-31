/*
Hume Library
Copyright (C) 2015 Marshall Clyburn

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
USA

*/

#ifndef LOG_H
#define LOG_H

#include <string>

#include "Component.h"
#include "LogMode.h"

class Log : public Component
{
public:
    Log();
    virtual ~Log();

    virtual void log(const std::string& msg) = 0;

    void set_mode(const LogMode l);
    LogMode get_mode();

protected:
    LogMode mode;
};

#endif
