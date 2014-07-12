#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

namespace hm
{
	enum TimeUnit
	{
		MILLISECONDS = 1,
		SECONDS = 1000,
		MINUTES = 60000
	};
	
	/* Defines a class to act as a stopwatch
	   in a Hume-based application. */
	class Timer
	{
	public:
		Timer();
		~Timer();

		void start(); // Starts the timer.
		void pause(); // Pauses the timer.
		void unpause(); // Unpauses the timer.
		void reset(); // Resets the timer.

		float getTime(); // Returns the amount of time passed.
		float getTime(TimeUnit unit);

		bool isPaused(); // Returns paused status.
		bool isStarted(); // Returns started status.

	private:
		float startTime; // The ticks counted when the timer started.
		float pauseTime; // The ticks counted when the timer paused.

		bool started; // Whether the timer is started or not.
		bool paused; // Whether the timer is paused or not.
	};
}

#endif
