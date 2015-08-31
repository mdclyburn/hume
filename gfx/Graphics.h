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

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL_ttf.h>

#include "../core/Component.h"
#include "Image.h"
#include "Window.h"

class Graphics : public Component
{
public:
    Graphics();
    virtual ~Graphics();

    virtual void initialize();
    virtual void shutdown();

    void set_window(Window* const w);
    Window* get_window() const;

    Image* load_image(const std::string& filename);
    Image* load_image(const std::string& filename, const Uint8 r, const Uint8 g, const Uint8 b);

    void draw(const Blittable* const b, const Properties& p);
    void clear();
    void refresh();

protected:
    Window* window;
};

#endif
