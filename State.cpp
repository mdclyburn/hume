/*
 Hume Library Version 0.5
 */

#include "State.h"

namespace hm
{
	State::State()
	{

	}
	
	State::~State()
	{
		
	}
	
	void State::setApplication(hm::Application* app)
	{
		this->app = app;
		return;
	}

	void State::setWindow(Window* window)
	{
		this->window = window;
		return;
	}
	
	void State::pop()
	{
		app->getStateManager()->popState();
		return;
	}
}
