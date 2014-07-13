/*
 Hume Library Version 0.4.2
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>

#include <SDL2/SDL.h>

#include "Game.h"
#include "Window.h"
#include "StateManager.h"
#include "GameState.h"

namespace hm
{
	class Game;

	/*
	 Defines the basic game state along with the necessary
	 functions for running when added to a StateManager.
	 */
	class GameState
	{
	public:
		GameState();

		void setGame(Game* game);
		void setWindow(Window* window);

		virtual void pause() = 0;
		virtual void resume() = 0;
		
		virtual bool init() = 0;
		virtual void processInput(SDL_Event& e) = 0;
		virtual void update() = 0;
		virtual void display() = 0;
		virtual void cleanup() = 0;
		
	protected:
		Game* game;
		Window* window;

		void pop();
	};
}

#endif
