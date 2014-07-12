/*
 Hume Library Version 0.4.2
 */

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

		void start();
		void pause();
		void unpause();
		void reset();

		float getTime();
		float getTime(TimeUnit unit);

		bool isPaused();
		bool isStarted();

	private:
		float startTime;
		float pauseTime;

		bool started;
		bool paused;
	};
}

#endif
