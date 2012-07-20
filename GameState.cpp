#include "GameState.h"

namespace hm
{
	GameState::GameState()
    {
        initted = false;
        clean = false;
	}

	void GameState::setGame(Game* game)
	{
		this->game = game;
		return;
	}

	void GameState::setWindow(Window* window)
	{
		this->window = window;
		return;
    }
}