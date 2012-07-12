#include "Game.h"

namespace hm
{
	Game::Game()
	{
		// Set up our members.
		window = new Window("No Title", 640, 480);
		manager = new StateManager(window);
	}

	Game::Game(std::string title)
	{
		window = new Window(title, 640, 480);
		manager = new StateManager(window);
	}

	Game::Game(std::string title, int width, int height, int bpp)
	{
		window = new Window(title, width, height, bpp);
		manager = new StateManager(window);
	}

	Game::~Game()
	{
		delete manager;
		delete window;
	}
}