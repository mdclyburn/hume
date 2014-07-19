/*
 Hume Library Version 0.5
 */

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "Application.h"
#include "State.h"
#include "Window.h"
#include <vector>

namespace hm
{
	class Application;
	class State;

	/*
	 The manager for all States that an Application uses. It
	 is responsible for state initialization and clean up
	 as well.
	 */
	class StateManager
	{
		public:
			StateManager();
			StateManager(Application* app, Window* window);
			~StateManager();

			void startState();
			void stopState();
			void resumeState();
			void pauseState();

			bool hasState();
			State* getCurrentState();

			bool pushState(State& s);
			void popState();
			void replaceState(State& s);
			void popAll();
		
		private:
			std::vector<State*> stack;
		Application* app;
			Window* window;
	};
};

#endif
