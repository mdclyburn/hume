#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"
#include "Window.h"
#include "StateManager.h"
#include "GameState.h"
#include <SDL/SDL.h>
#include <iostream>

namespace hm
{
	class Game;

	class GameState // Abstract class
	{
		public:
		    GameState(); // Basic constructor.

			void setGame(Game* game); // Sets the game pointer.
		    void setWindow(Window* window); // Sets the window pointer.

		    virtual void pause() = 0; // Suspends the current activity in the state.
		    virtual void resume() = 0; // Starts the state back up.

            virtual bool init() = 0; // Handles initialization.
            virtual void processInput(SDL_Event& e) = 0; // Handles user input.
            virtual void update() = 0; // Updates the state's internals.
            virtual void display() = 0; // Displays what's happening onscreen.
            virtual void cleanup() = 0; // Gets the state ready for dismissal.

		protected:
			Game* game; // Gives access to the game which the state belongs to.
			Window* window; // Gives access to the drawing window.
			bool initted; // Whether it has been initialized.
			bool clean; // Whether cleanup() has been run.	
	};
}

#endif
