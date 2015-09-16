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

#include "Window.h"

Window::Window() : window(nullptr), renderer(nullptr)
{
}

Window::~Window()
{
    if(window) destroy();
}

void Window::create()
{
    window = SDL_CreateWindow(settings.title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, settings.width, settings.height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    assert(window);
    assert(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    return;
}

void Window::destroy()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = nullptr;
    renderer = nullptr;

    return;
}

void Window::apply(WindowSettings& w)
{
    // update the window based on what's changed
    if(settings.fullscreen != w.fullscreen)
    {
	settings.fullscreen = w.fullscreen;
	if(window)
	{
	    if(settings.fullscreen)
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	    else
		SDL_SetWindowFullscreen(window, 0);
	}
    }
    if(settings.title.compare(w.title) != 0)
    {
	settings.title = w.title;
	if(window) SDL_SetWindowTitle(window, settings.title.c_str());
    }
    if(settings.width != w.width ||
       settings.height != w.height)
    {
	// go ahead and assign the resolution, followed by a resize
	settings.width = w.width;
	settings.height = w.height;
	if(window) SDL_SetWindowSize(window, settings.width, settings.height);
    }

    return;
}

WindowSettings Window::get_settings() const
{
    return settings;
}

SDL_Window* Window::get_window()
{
    return window;
}

SDL_Renderer* Window::get_renderer()
{
    return renderer;
}

void Window::draw(const Blittable* const b, const Properties& p)
{
    SDL_Rect r;
    r.x = p.x;
    r.y = p.y;

    // use the provided width and height if specified
    if(p.w == 0 || p.h == 0)
    {
		r.w = b->get_width();
		r.h = b->get_height();
    }
    else // default width and height
    {
		r.w = p.w;
		r.h = p.h;
    }

    if(p.sw == 0 || p.sh == 0)
		SDL_RenderCopy(renderer, b->get_texture(), nullptr, &r);
    else
    {
		SDL_Rect s;
		s.x = p.sx;
		s.y = p.sy;
		s.w = p.sw;
		s.h = p.sh;
		SDL_RenderCopy(renderer, b->get_texture(), &s, &r);
    }

    return;
}

void Window::present()
{
    SDL_RenderPresent(renderer);
}

void Window::clear()
{
    SDL_RenderClear(renderer);
    return;
}
