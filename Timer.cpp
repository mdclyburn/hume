#include "Timer.h"

namespace hm
{
	Timer::Timer() : started(false), paused(false), startTime(0), pauseTime(0)
	{
		// Initialize values.
	}

	Timer::~Timer()
	{
		// Nothing to do here...
	}

	void Timer::start()
	{
		started = true;
		paused = false;
		startTime = SDL_GetTicks();
		return;
	}

	void Timer::pause()
	{
		paused = true;
		pauseTime = SDL_GetTicks() - startTime;
		return;
	}

	void Timer::unpause()
	{
		if(paused)
		{
			paused = false;
			startTime = SDL_GetTicks() - pauseTime;
			pauseTime = 0;
		}

		return;
	}

	void Timer::reset()
	{
		started = false;
		paused = false;
		return;
	}

	float Timer::getTime()
	{
		if(started)
		{
			if(paused)
				return pauseTime;
			else
				return SDL_GetTicks() - startTime;
		}

		return 0;
	}

	bool Timer::isPaused()
	{
		return paused;
	}

	bool Timer::isStarted()
	{
		return started;
	}
}