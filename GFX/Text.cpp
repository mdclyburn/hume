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

#include "Text.h"

namespace hume
{
    Text::Text() : Blittable(), font(nullptr), text("")
    {
        color.r = color.g = color.b = 255;
        bg_color.r = bg_color.g = bg_color.b = 0;
    }

    Text::~Text()
    {
    }

    void Text::set_font(Font* const font)
    {
        this->font = font;
        return;
    }

    void Text::set_text(const std::string& text, SDL_Renderer* r)
    {
        if(!r) throw SDLException("Text::set_text requires a renderer.");

        destroy();

        SDL_Surface* surface = nullptr;
        RenderMode rm = font->get_render_mode();
        if(rm == RenderMode::Solid)
            surface = TTF_RenderText_Solid(font->get_font(), text.c_str(), color);
        else if(rm == RenderMode::Shaded)
            surface = TTF_RenderText_Shaded(font->get_font(), text.c_str(), color, bg_color);
        else
            surface = TTF_RenderText_Blended(font->get_font(), text.c_str(), color);

        if(!surface) throw SDLException();

        texture = SDL_CreateTextureFromSurface(r, surface);
        if(!texture) throw SDLException();
        SDL_QueryTexture(texture, nullptr, nullptr, &info.w, &info.h);

        return;
    }

    std::string Text::get_text() const
    {
        return text;
    }

    void Text::set_color(const Uint8 r, const Uint8 g, const Uint8 b)
    {
        color.r = r;
        color.g = g;
        color.b = b;

        return;
    }

    void Text::set_bg_color(const Uint8 r, const Uint8 g, const Uint8 b)
    {
        bg_color.r = r;
        bg_color.g = g;
        bg_color.b = b;

        return;
    }
}
