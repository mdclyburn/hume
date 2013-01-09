#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>
#include "Window.h"
#include "StateManager.h"
#include "Logger.h"
#include "Timer.h"
#include <string>
#include <iostream>

namespace hm
{
	class StateManager;

	class Game // Defines the basic structure of a typical game.
	{
	public:
		Game(); // Basic ctor.
		Game(std::string title); // Constructs window with title.
		Game(std::string title, int width, int height, int bpp = 32); // Constructs with title and dimensions.
		~Game(); // Basic dtor.

		virtual void run() = 0; // Starts the game.

		// +++++ FRAME RATE FUNCTIONS +++++
		void setCapFrameRate(bool b); // Whether to cap frame rate or not
		bool frameRateIsCapped(); // Gets the frame rate cap bool.
		void setFrameRate(int i); // Set the frame rate.
		float getMaxFrameTime(); // Gets the highest possible frame time.
		float getCappedFrameTime(); // Gets the capped frame time.
		float getMaxFrameRate(); // Gets the highest possible frame rate.
		float getCappedFrameRate(); // Gets the capped frame rate.
		float getFrameRate(); // Gets the frame rate, whether it's capped or uncapped.
		// ++++++++++++++++++++++++++++++++

		void log(std::string msg, LogLevel level = INFO); // Writes out a log message to the Logger object.

		void quit(); // Initiates game cleanup procedure.

		StateManager* getStateManager(); // Returns pointer to the StateManager object 'manager'.

	protected:
        bool running; // Whether the game is running or not.

		SDL_Event e; // SDL's event structure.

		bool capFrameRate; // Whether to cap the game's frame rate.
		int framerate; // Frames to show in a second.
		Timer frameTimer; // Timer to handle frame rates.
		float maxFrameTime; // The average highest frame time capable.
		float cappedFrameTime; // The average frame time performed at.

		Window* window; // The game window.
		StateManager* manager; // Maintains the states.
		Logger* logger; // Logs messages from the system.

        virtual bool init() = 0; // Initialization of the game.
        virtual void processInput() = 0; // Process input for the game.
        virtual void update() = 0; // Update internals.
        virtual void display() = 0; // Show changes.
        virtual void loop(); // Performs the above three functions in a loop.
        virtual void cleanup() = 0; // Frees resources.

        // SDL Initialization Functions
        void initSdl(); // Initializes the whole SDL subsystem.
        void initSdlImage(); // Initializes the sdl_image library.
        void initSdlMixer(); // Initializes the sdl_mixer library.
        void initSdlTtf(); // Initializes the sdl_ttf library.
	};
}

#endif
