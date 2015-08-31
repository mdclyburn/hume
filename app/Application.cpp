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

#include "Application.h"

Application::Application() : running(false)
{
    set_frame_limit(30);
}

Application::~Application()
{
}

void Application::stop()
{
    running = false;
    return;
}

void Application::set_frame_limit(const unsigned int frame_rate)
{
    frame_time = float(1000) / float(frame_rate);
    return;
}

void Application::initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    return;
}

void Application::shutdown()
{
    SDL_Quit();
    return;
}

void Application::loop()
{
    running = true;
    while(running && !state_stack.empty())
    {
	// interact directly with SDL for frame timing to reduce
	// overhead incurred by function calls
	const unsigned int frame_start = SDL_GetTicks();
	
	process_input();
	update();
	display();

	const unsigned int frame_duration = SDL_GetTicks() - frame_start;
	if(frame_duration < frame_time)
	    SDL_Delay(frame_time - frame_duration);
    }
}

void Application::push(State* const s)
{
    state_stack.back()->pause();
    s->initialize();
    state_stack.push_back(s);

    return;
}

State* Application::pop()
{
    state_stack.back()->shutdown();
    State* const s = state_stack.back();
    state_stack.pop_back();
    state_stack.back()->resume();

    return s;
}
