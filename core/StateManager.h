#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <cassert>
#include <vector>

#include "State.h"

class StateManager
{
public:
    StateManager();
    virtual ~StateManager();

    bool has_state();
    State* get_current();

    void push(State* const state);
    void pop();
    void pop_all();

protected:
    std::vector<State*> stack;
};

#endif
