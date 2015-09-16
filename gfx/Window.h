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

#ifndef WINDOW_H
#define WINDOW_H

#include "Blittable.h"
#include "Properties.h"
#include "WindowSettings.h"

class Window
{
public:
    Window();
    virtual ~Window();

    void create();
    void destroy();

    void apply(WindowSettings& w);

    WindowSettings get_settings() const;
    SDL_Window* get_window();
    SDL_Renderer* get_renderer();

    void draw(const Blittable* const b, const Properties& p);
    void present();
    void clear();

protected:
    SDL_Window* window;
    SDL_Renderer* renderer;
    WindowSettings settings;
};

#endif