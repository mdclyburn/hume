// Hume Library Version 0.7

#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>

#include <SDL2/SDL.h>

#include "../core/Timer.h"
#include "State.h"

class Application
{
public:
    Application();
    virtual ~Application();

    virtual void run() = 0;
    void stop();

    void set_frame_limit(const unsigned int frame_rate);

protected:
    virtual void initialize();
    virtual void shutdown();
 
    virtual void loop();
    virtual void process_input() = 0;
    virtual void update() = 0;
    virtual void display() = 0;

    virtual void push(State* const s);
    virtual State* pop();

    bool running;
    float frame_time;
    std::vector<State*> state_stack;
};

#endif
