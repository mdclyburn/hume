// Hume Library Version 0.6

#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "Window.h"
#include "StateManager.h"
#include "Logger.h"
#include "Timer.h"

namespace hm
{
	class StateManager;

	/*
	 Provides much of the functionality needed to get
	 started with constructing an application.
	 */
	class Application
	{
	public:
		Application();
		Application(std::string title);
		Application(std::string title, unsigned int width, unsigned int height, bool fs = false);
		virtual ~Application();

		virtual void run() = 0;

		// Frame Rate Management
		void capFrameRate(bool b);
		bool frameRateIsCapped();
		void setFrameRate(int i);
		float getFrameRate();

		void log(std::string msg, LogLevel level = INFO);

		void quit();

		StateManager* getStateManager();

	protected:
        bool running;

		SDL_Event e;

		std::string title;
		bool cap_frame_rate;
		int framerate;
		Timer frameTimer;

		Window* window;
		StateManager* manager;

       	virtual bool init() = 0;
       	virtual void processInput() = 0;
       	virtual void update() = 0;
       	virtual void display() = 0;
       	virtual void loop();
       	virtual void cleanup() = 0;
		
		void SDLInit();
		void SDLQuit();
	};
}

#endif
