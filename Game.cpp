#include "Game.h"

namespace hm
{
	Game::Game()
	{
		// Set up our members.
		window = new Window("No Title", 640, 480);
		manager = new StateManager(window);
	}

	Game::~Game()
	{
		delete manager;
		delete window;
	}
}