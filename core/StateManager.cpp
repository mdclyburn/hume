#include "StateManager.h"

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
}

bool StateManager::has_state()
{
    return stack.size() != 0;
}

State* StateManager::get_current()
{
    return stack.back();
}

void StateManager::push(State* const state)
{
    if(stack.size() > 0)
	stack.back()->pause();

    assert(state->initialize());
    if(!stack.empty())
	stack.push_back(state);

    return;
}

void StateManager::pop()
{
    stack.back()->cleanup();
    stack.pop_back();
    stack.back()->resume();

    return;
}

void StateManager::pop_all()
{
    while(!stack.empty())
	pop();

    return;
}
