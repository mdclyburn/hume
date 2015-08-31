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

#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>

#include <SDL2/SDL.h>

#include "../core/Timer.h"
#include "State.h"

class Application
{
public:
    Application();
    virtual ~Application();

    virtual void run() = 0;
    void stop();

    void set_frame_limit(const unsigned int frame_rate);

protected:
    virtual void initialize();
    virtual void shutdown();
 
    virtual void loop();
    virtual void process_input() = 0;
    virtual void update() = 0;
    virtual void display() = 0;

    virtual void push(State* const s);
    virtual State* pop();

    bool running;
    float frame_time;
    std::vector<State*> state_stack;
};

#endif
