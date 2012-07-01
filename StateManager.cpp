#include "StateManager.h"

namespace hm
{
	StateManager::StateManager()
	{
		// Nothing to do here.
	}

	void StateManager::startState()
	{
		if(!stack.empty())
			stack.back()->run();
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
		stack.push_back(&gs);
		return;
	}

	void StateManager::popState()
	{
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
			stack.pop_back();
			pushState(gs);
		}
		else
		{
			pushState(gs);
		}

		return;
	}
};