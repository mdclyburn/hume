#include "GameState.h"

namespace hm
{
	GameState::GameState()
    {
        initted = false;
        clean = false;
	}

	void GameState::setWindow(Window* window)
	{
		this->window = window;
		return;
    }
};
