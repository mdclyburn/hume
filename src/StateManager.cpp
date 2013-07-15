#include "StateManager.h"

namespace hm
{
	StateManager::StateManager() : game(NULL), window(NULL)
	{
	}

	StateManager::StateManager(Game* game, Window* window) : game(game), window(window)
	{
	}

	StateManager::~StateManager()
	{
		game = NULL;
		window = NULL;
	}

	void StateManager::startState()
	{
		if(!stack.empty())
			stack.back()->init();
		return;
	}

	void StateManager::stopState()
	{
		if(!stack.empty())
		{
			// Implement cleanup...
		}
		return;
	}

	void StateManager::pauseState()
	{
		// If state present, pause it.
		if(!stack.empty())
			stack.back()->pause();
		return;
	}

	void StateManager::resumeState()
	{
		// If state present, resume it.
		if(!stack.empty())
			stack.back()->resume();
		return;
	}

	bool StateManager::hasState()
	{
		 return !stack.empty();
	}

	GameState* StateManager::getCurrentState()
	{
		if(stack.empty())
			return NULL;
		return stack.back();
	}

	void StateManager::pushState(GameState& gs)
	{
		// Send the pause command to the current state.
		pauseState();

		//Set up the next state.
		stack.push_back(&gs);
		stack.back()->setGame(game);
        	stack.back()->setWindow(window);
		if(!stack.back()->init())
			std::cout << "Something's up with the initialization..." << std::endl;
		return;
	}

	void StateManager::popState()
	{
		// Clean up.
		stack.back()->cleanup();

		// Take it off the stack.
		stack.pop_back();
		resumeState();
		return;
	}

	void StateManager::replaceState(GameState& gs)
	{
		// Check that it's not empty
		if(!stack.empty())
		{
			stack.back()->cleanup();
			stack.pop_back();
			pushState(gs);
		}
		else
			pushState(gs);

		return;
    	}

	void StateManager::popAll()
	{
		while(!stack.empty())
		{
			if(stack.back() == NULL)
			{
				stack.pop_back();
				continue;
			}

			stack.back()->cleanup();
			stack.pop_back();
		}
		
		return;
	}
}
