#ifndef timer_h
#define timer_h

#include <SDL2/SDL.h>

class Timer
{
public:
    Timer();
    virtual ~Timer();

    void start();
    void pause();
    void unpause();
    void reset();

    uint32_t get_elapsed_time() const;

    bool is_running() const;
    bool is_paused() const;

protected:
    bool running;
    bool paused;
    uint32_t start_time;
    uint32_t pause_time;
};

#endif
