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

#ifndef BLITTABLE_H
#define BLITTABLE_H

#include <cassert>

#include "SDL2/SDL.h"

class Blittable
{
public:
    Blittable();
    virtual ~Blittable();

    void set_alpha(const Uint8 a);
    void modify_alpha(const short m);
    Uint8 get_alpha() const;

    unsigned int get_width() const;
    unsigned int get_height() const;

    SDL_Texture* get_texture() const;
    void destroy();

protected:
    SDL_Rect info;
    SDL_Texture* texture;
};

#endif
