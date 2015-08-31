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

#ifndef FONT_H
#define FONT_H

#include <cassert>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "RenderMode.h"

class Font
{
public:
    Font();
    virtual ~Font();

    void open(const std::string& file_name, const unsigned int pt_size);
    void close();

    void set_size(const unsigned int pt_size);

    void set_render_mode(const RenderMode& render_mode);
    RenderMode get_render_mode();

    TTF_Font* get_font();

protected:
    TTF_Font* font;
    std::string file_name;
    RenderMode render_mode;
};

#endif
