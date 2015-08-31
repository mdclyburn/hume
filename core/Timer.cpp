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

#include "Timer.h"

Timer::Timer() : running(false), paused(false), start_time(0), pause_time(0)
{
}

Timer::~Timer()
{
}

void Timer::start()
{
    running = true;
    paused = false;
    start_time = SDL_GetTicks();

    return;
}

void Timer::pause()
{
    paused = true;
    pause_time = SDL_GetTicks() - start_time;

    return;
}

void Timer::unpause()
{
    if(paused)
    {
	paused = false;
	start_time = SDL_GetTicks() - pause_time;
	pause_time = 0;
    }

    return;
}

void Timer::reset()
{
    running = false;
    paused = false;

    return;
}

uint32_t Timer::get_elapsed_time() const
{
    if(running && paused)
	return pause_time;
    else if(!running && !paused)
	return 0;
    else
	return SDL_GetTicks() - start_time;
}

bool Timer::is_running() const
{
    return running;
}

bool Timer::is_paused() const
{
    return paused;
}
