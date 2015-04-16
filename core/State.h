#ifndef STATE_H
#define STATE_H

#include <SDL2/SDL.h>

#include "Log.h"

class Graphics;
class StateManager;

class State
{
public:
    State();
    virtual ~State();

    virtual bool initialize() = 0;
    virtual void cleanup() = 0;
 
    virtual void pause() = 0;
    virtual void resume() = 0;

    virtual void process_input(SDL_Event& e) = 0;
    virtual void update() = 0;
    virtual void display() = 0;

    virtual void set_log(Log* const log);
    virtual void set_gfx(Graphics* const gfx);
    virtual void set_manager(StateManager* const manager);
    
protected:
    Log* log;
    Graphics* gfx;
    StateManager* manager;

    void pop();
};

#endif
