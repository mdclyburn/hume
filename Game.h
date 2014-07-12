#ifndef GAME_H
#define GAME_H

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

	class Game
	{
	public:
		Game();
		Game(std::string title);
		Game(std::string title, unsigned int width, unsigned int height, bool fs = false);
		~Game();
		
		virtual void SDLInit();

		virtual void run() = 0;

		void setCapFrameRate(bool b);
		bool frameRateIsCapped();
		void setFrameRate(int i);
		float getMaxFrameTime();
		float getCappedFrameTime();
		float getMaxFrameRate();
		float getCappedFrameRate();
		float getFrameRate();
		void frameRateView(bool b);

		void log(std::string msg, LogLevel level = INFO);

		void quit();

		StateManager* getStateManager();

	protected:
        bool running;

		SDL_Event e;

		std::string title;
		bool capFrameRate;
		bool displayFrameRate;
		int framerate;
		Timer frameTimer;
		float maxFrameTime;
		float cappedFrameTime;

		Window* window;
		StateManager* manager;

       	virtual bool init() = 0;
       	virtual void processInput() = 0;
       	virtual void update() = 0;
       	virtual void display() = 0;
       	virtual void loop();
       	virtual void cleanup() = 0;

       	bool initSdl();
       	bool initSdlImage();
       	bool initSdlMixer();
       	bool initSdlTtf();
	};
}

#endif
