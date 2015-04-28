#include "Application.h"

Application::Application() : running(false)
{
    set_frame_limit(30);
}

Application::~Application()
{
}

void Application::stop()
{
    running = false;
    return;
}

void Application::set_frame_limit(const unsigned int frame_rate)
{
    frame_time = float(1000) / float(frame_rate);
    return;
}

void Application::initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    return;
}

void Application::shutdown()
{
    SDL_Quit();
    return;
}

void Application::loop()
{
    running = true;
    while(running && !state_stack.empty())
    {
	// interact directly with SDL for frame timing to reduce
	// overhead incurred by function calls
	const unsigned int frame_start = SDL_GetTicks();
	
	process_input();
	update();
	display();

	const unsigned int frame_duration = SDL_GetTicks() - frame_start;
	if(frame_duration < frame_time)
	    SDL_Delay(frame_time - frame_duration);
    }
}

void Application::push(State* const s)
{
    state_stack.back()->pause();
    s->initialize();
    state_stack.push_back(s);

    return;
}

State* Application::pop()
{
    state_stack.back()->shutdown();
    State* const s = state_stack.back();
    state_stack.pop_back();
    state_stack.back()->resume();

    return s;
}
