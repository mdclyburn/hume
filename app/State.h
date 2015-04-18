#ifndef STATE_H
#define STATE_H

#include "SDL2/SDL.h"

class State
{
public:
    State();
    virtual ~State();

    virtual void pause() = 0;
    virtual void resume() = 0;

    virtual void initialize() = 0;
    virtual void shutdown() = 0;
 
    virtual void process_input(const SDL_Event& e) = 0;
    virtual void update() = 0;
    virtual void display() = 0;
};

#endif
