#include "GameState.h"

namespace hm
{
	GameState::GameState()
	{
		// Nothing to do here...
	}

	GameState::GameState(Window* window)
	{
		this->window = window;
	}

	void GameState::setWindow(Window* window)
	{
		this->window = window;
		return;
	}
};