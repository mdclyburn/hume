#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "Game.h"
#include "GameState.h"
#include "Window.h"
#include <vector>

namespace hm
{
	class Game;
	class GameState;

	/*
	 The manager for all GameStates that a Game uses. It
	 is responsible for state initialization and clean up
	 as well.
	 */
	class StateManager
	{
		public:
			StateManager();
			StateManager(Game* game, Window* window);
			~StateManager();

			void startState();
			void stopState();
			void resumeState();
			void pauseState();

			bool hasState();
			GameState* getCurrentState();

			bool pushState(GameState& gs);
			void popState();
			void replaceState(GameState& gs);
			void popAll();
		
		private:
			std::vector<GameState*> stack;
			Game* game;
			Window* window;
	};
};

#endif
