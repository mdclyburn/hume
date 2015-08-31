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

#ifndef TEXT_H
#define TEXT_H

#include <string>

#include <SDL2/SDL.h>

#include "Blittable.h"
#include "Font.h"

class Text : public Blittable
{
public:
    Text();
    virtual ~Text();

    void set_font(Font* const font);

    void set_text(const std::string& text, SDL_Renderer* r);
    std::string get_text();

    void set_color(const Uint8 r, const Uint8 g, const Uint8 b);
    void set_bg_color(const Uint8 r, const Uint8 g, const Uint8 b);

protected:
    Font* font;
    std::string text;
    SDL_Color color;
    SDL_Color bg_color;
};

#endif
