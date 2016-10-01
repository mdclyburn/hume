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

#include "Image.h"

namespace hume
{
    Image::Image() : Blittable()
    {
        color_key.r = 255;
        color_key.g = 0;
        color_key.b = 255;
    }

    Image::Image(const Uint8 r, const Uint8 g, const Uint8 b) : Blittable()
    {
        color_key.r = r;
        color_key.g = g;
        color_key.b = b;
    }

    Image::~Image()
    {
    }

    void Image::open(const std::string& filename, SDL_Renderer* const renderer)
    {
        SDL_Surface* surface = IMG_Load(filename.c_str());
        if(!surface) throw SDLException();

        // apply color keying
        const Uint32 key = SDL_MapRGB(surface->format, color_key.r, color_key.g, color_key.b);
        SDL_SetColorKey(surface, SDL_TRUE, key);

        // convert to texture
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if(!texture) throw SDLException();
        SDL_FreeSurface(surface);

        // get dimensions
        SDL_QueryTexture(texture, nullptr, nullptr, &info.w, &info.h);

        return;
    }

    void Image::close()
    {
        destroy();
        return;
    }
}
