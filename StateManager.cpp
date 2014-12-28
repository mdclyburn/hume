// Hume Library Version 0.6

#include "StateManager.h"

namespace hm
{
	StateManager::StateManager() : app(NULL), window(NULL)
	{
	}

	StateManager::StateManager(const Application* const app, const Window* const window) : app(app), window(window)
	{
	}

	StateManager::~StateManager()
	{
		app = NULL;
		window = NULL;
	}

	void StateManager::startState() const
	{
		if(!stack.empty())
			stack.back()->init();
		return;
	}

	void StateManager::stopState() const
	{
		if(!stack.empty())
			stack.back()->cleanup();
		return;
	}

	void StateManager::pauseState() const
	{
		// If state present, pause it.
		if(!stack.empty())
			stack.back()->pause();
		return;
	}

	void StateManager::resumeState() const
	{
		// If state present, resume it.
		if(!stack.empty())
			stack.back()->resume();
		return;
	}

	bool StateManager::hasState() const
	{
		 return !stack.empty();
	}

	State* StateManager::getCurrentState() const
	{
		if(stack.empty())
			return NULL;
		return stack.back();
	}

	bool StateManager::pushState(State& s)
	{
		// Send the pause command to the current state.
		pauseState();

		//Set up the next state.
		stack.push_back(&s);
		stack.back()->setApplication(app);
        	stack.back()->setWindow(window);
		if(!stack.back()->init())
		{
			Logger::log("State initialization reported failure.", ERROR);
			return false;
		}
		
		return true;
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

	void StateManager::replaceState(State& s)
	{
		// Check that it's not empty
		if(!stack.empty())
		{
			stack.back()->cleanup();
			stack.pop_back();
			pushState(s);
		}
		else
			pushState(s);

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
