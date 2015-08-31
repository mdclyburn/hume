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

#include "Graphics.h"

Graphics::Graphics() : window(nullptr)
{
}

Graphics::~Graphics()
{
    if(window) delete window;
}

void Graphics::initialize()
{
    const int types = IMG_INIT_JPG | IMG_INIT_PNG;
    int result = IMG_Init(types);
    assert(result == types);
    
    result = TTF_Init();
    assert(result == 0);

    return;
}

void Graphics::shutdown()
{
    IMG_Quit();
    TTF_Quit();

    return;
}

void Graphics::set_window(Window* const w)
{
    window = w;
    return;
}

Window* Graphics::get_window() const
{
    return window;
}

Image* Graphics::load_image(const std::string& filename)
{
    Image* image = new Image();
    image->open(filename, window->get_renderer());

    return image;
}

Image* Graphics::load_image(const std::string& filename, const Uint8 r, const Uint8 g, const Uint8 b)
{
    Image* image = new Image(r, g, b);
    image->open(filename, window->get_renderer());

    return image;
}

void Graphics::draw(const Blittable* const b, const Properties& p)
{
    window->draw(b, p);
    return;
}

void Graphics::clear()
{
	window->clear();
	return;
}

void Graphics::refresh()
{
    window->present();
    return;
}
