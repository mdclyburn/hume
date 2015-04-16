#include "Application.h"

Application::Application() : running(false), log(nullptr), graphics(nullptr), manager(nullptr)
{
    set_frame_rate(40);
}

Application::~Application()
{
    manager->pop_all();
    graphics->shutdown();
    log->shutdown();
}

void Application::set_frame_rate(const unsigned int i)
{
    frame_time = (float) 1000 / i;
    return;
}

float Application::get_frame_rate() const
{
    return (float) 1000 / frame_time;
}
