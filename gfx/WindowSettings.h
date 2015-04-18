// Hume Library Version 0.7

#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

#include <cassert>
#include <string>

#include <SDL2/SDL.h>

struct WindowSettings
{
    bool fullscreen;
    std::string title;
    unsigned int width;
    unsigned int height;

    WindowSettings();
};

void set_best_fullscreen_mode();

#endif
