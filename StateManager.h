// Hume Library Version 0.6

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
			StateManager(const Application* const app, const Window* const window);
			~StateManager();

			void startState() const;
			void stopState() const;
			void resumeState() const;
			void pauseState() const;

			bool hasState() const;
			State* getCurrentState() const;

			bool pushState(State& s);
			void popState();
			void replaceState(State& s);
			void popAll();
		
		private:
			std::vector<State*> stack;
			const Application* app;
			const Window* window;
	};
};

#endif
