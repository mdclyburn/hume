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
