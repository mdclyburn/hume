/*
 Hume Library Version 0.5
 */

#ifndef STATE_H
#define STATE_H

#include <iostream>

#include <SDL2/SDL.h>

#include "Application.h"
#include "Window.h"
#include "StateManager.h"

namespace hm
{
	class Application;

	/*
	 Defines the basic application state along with the necessary
	 functions for running when added to a StateManager.
	 */
	class State
	{
	public:
		State();
		virtual ~State();

		void setApplication(Application* app);
		void setWindow(Window* window);

		virtual void pause() = 0;
		virtual void resume() = 0;
		
		virtual bool init() = 0;
		virtual void processInput(SDL_Event& e) = 0;
		virtual void update() = 0;
		virtual void display() = 0;
		virtual void cleanup() = 0;
		
	protected:
		Application* app;
		Window* window;

		void pop();
	};
}

#endif
