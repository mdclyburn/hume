#ifndef APPLICATION_H
#define APPLICATION_H

#include "../gfx/Graphics.h"
#include "Log.h"
#include "StateManager.h"
#include "Timer.h"

class Application
{
public:
    Application();
    virtual ~Application();

    virtual void run() = 0;

    void set_frame_rate(const unsigned int i);
    float get_frame_rate() const;

protected:
    bool running;
    float frame_time;
    Log* log;
    Graphics* graphics;
    StateManager* manager;

    virtual bool init() = 0;
    virtual void process_input() = 0;
    virtual void update() = 0;
    virtual void display() = 0;
    virtual void loop();
    virtual void cleanup() = 0;
};

#endif
