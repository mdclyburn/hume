#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Window.h"
#include <SDL\SDL.h>
#include <iostream>

namespace hm
{
	class GameState // Abstract class
	{
		public:
			GameState(); // Basic constructor.

			void setWindow(Window* window); // Sets the window pointer.
			virtual void run() = 0; // Automatically inits and starts the state.

			virtual void pause() = 0; // Suspends the current activity in the state.
			virtual void resume() = 0; // Starts the state back up.

			virtual void checkEvents(SDL_Event e); // Checks state events.

		protected:
			Window* window; // Gives access to the drawing window.
			bool initted; // Whether it has been initialized.
			bool clean; // Whether cleanup() has been run.

			virtual bool init() = 0; // Handles initialization.
			virtual void processInput() = 0; // Handles user input.
			virtual void update() = 0; // Updates the state's internals.
			virtual void display() = 0; // Displays what's happening onscreen.
			virtual void cleanup() = 0; // Gets the state ready for dismissal.
			virtual void loop() = 0; // The state's loop
	};
};

#endif