#ifndef GAMESTATE_H
#define GAMESTATE_H

namespace hm
{
	class GameState // Abstract class
	{
		public:
			GameState(); // Basic constructor.

			virtual void run() = 0; // Automatically inits and starts the state.

			virtual void pause() = 0; // Suspends the current activity in the state.
			virtual void resume() = 0; // Starts the state back up.
		private:
			virtual bool init() = 0; // Handles initialization.
			virtual void processInput() = 0; // Handles user input.
			virtual void update() = 0; // Updates the state's internals.
			virtual void display() = 0; // Displays what's happening onscreen.
			virtual void loop() = 0; // The main loop of the state.
			virtual void cleanup() = 0; // Gets the state ready for dismissal.
	};
};

#endif