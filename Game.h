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
		Window* window; // The game window.
		StateManager* manager; // Maintains the states.
	};
}

#endif