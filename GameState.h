#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Window.h"
#include "StateManager.h"
#include "GameState.h"
#include <SDL/SDL.h>
#include <iostream>

namespace hm
{
	class StateManager;
	class GameState // Abstract class
	{
		public:
		    GameState(); // Basic constructor.

		    void setWindow(Window* window); // Sets the window pointer.
			void setManager(StateManager* manager); // Sets the manager pointer.
			void setNext(GameState* next); // Sets the next pointer.

		    virtual void pause() = 0; // Suspends the current activity in the state.
		    virtual void resume() = 0; // Starts the state back up.

            virtual bool init() = 0; // Handles initialization.
            virtual void processInput(SDL_Event& e) = 0; // Handles user input.
            virtual void update() = 0; // Updates the state's internals.
            virtual void display() = 0; // Displays what's happening onscreen.
            virtual void cleanup() = 0; // Gets the state ready for dismissal.

		protected:
			Window* window; // Gives access to the drawing window.
			StateManager* manager; // Allows state management from GameStates.
			GameState* next; // The state to be pushed after a state finishes execution.
			bool initted; // Whether it has been initialized.
			bool clean; // Whether cleanup() has been run.	
	};
}

#endif
