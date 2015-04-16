#include "State.h"

State::State() : log(nullptr), gfx(nullptr), manager(nullptr)
{
}

State::~State()
{
}

void State::set_log(Log* const log)
{
    this->log = log;
    return;
}

void State::set_gfx(Graphics* const gfx)
{
    this->gfx = gfx;
    return;
}

void State::set_manager(StateManager* const manager)
{
    this->manager = manager;
    return;
}
