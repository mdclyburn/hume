#include "WindowSettings.h"

WindowSettings::WindowSettings() : fullscreen(false), title("Hume Window"), width(800), height(450)
{
}

void set_best_fullscreen_mode(WindowSettings& settings)
{
    settings.fullscreen = true;

    // find the best available fullscreen resolution
    assert(SDL_GetNumDisplayModes(0) > 0);
    SDL_DisplayMode display_mode;

    assert(SDL_GetDisplayMode(0, 0, &display_mode) == 0);
    settings.width = display_mode.w;
    settings.height = display_mode.h;

    return;
}
