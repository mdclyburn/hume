/*
 Hume Library Version 0.4.2
 */

#include "GameState.h"

namespace hm
{
	GameState::GameState()
	{

	}
	
	void GameState::setApplication(hm::Application* app)
	{
		this->app = app;
		return;
	}

	void GameState::setWindow(Window* window)
	{
		this->window = window;
		return;
	}
	
	void GameState::pop()
	{
		game->getStateManager()->popState();
		return;
	}
}
