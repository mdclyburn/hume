#include "GameState.h"

namespace hm
{
	GameState::GameState()
	{
		// Nothing to do here...
	}

	void GameState::setWindow(Window* window)
	{
		this->window = window;
		return;
	}

	void GameState::checkEvents(SDL_Event e)
	{
		std::cout << "WARNING: Parent class checkEvents(SDL_Event e) used." << std::endl;
		return;
	}
};