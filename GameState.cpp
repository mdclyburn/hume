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

	void GameState::setManager(StateManager* manager)
	{
		this->manager = manager;
		return;
	}

	void GameState::setNext(GameState* next)
	{
		this->next = next;
		return;
	}
}