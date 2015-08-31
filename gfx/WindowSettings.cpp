/*
Hume Library
Copyright (C) 2015 Marshall Clyburn

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
USA
*/

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
