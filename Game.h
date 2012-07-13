#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "StateManager.h"
#include <string>

namespace hm
{
	class Game // Defines the basic structure of a typical game.
	{
	public:
		Game(); // Basic ctor.
		Game(std::string title); // Constructs window with title.
		Game(std::string title, int width, int height, int bpp = 32); // Constructs with title and dimensions.
		~Game(); // Basic dtor.

		virtual void run() = 0; // Starts the game.

	protected:
        bool running; // Whether the game is running or not.
		Window* window; // The game window.
		StateManager* manager; // Maintains the states.

        virtual bool init() = 0; // Initialization of the game.
        virtual void processInput() = 0; // Process input for the game.
        virtual void update() = 0; // Update internals.
        virtual void display() = 0; // Show changes.
        virtual void loop(); // Performs the above three functions in a loop.
        virtual void cleanup() = 0; // Frees resources.
	};
}

#endif
