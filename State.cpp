// Hume Library Version 0.6

#include "State.h"

namespace hm
{
	State::State() : app(nullptr), window(nullptr)
	{

	}
	
	State::~State()
	{
		
	}
	
	void State::setApplication(const Application* const app)
	{
		this->app = app;
		return;
	}

	void State::setWindow(const Window* const window)
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
