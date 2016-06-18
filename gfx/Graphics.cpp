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

namespace hume
{
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
		if(result != types) throw SDLException();
    
		result = TTF_Init();
		if(result != 0) throw SDLTTFException();

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

	void Graphics::draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
	{
		SDL_Renderer* const renderer = window->get_renderer();

		// We'll be restoring the blend mode and colors back to what they were.
		SDL_BlendMode previous;
		uint8_t rgba[4];
		SDL_GetRenderDrawBlendMode(renderer, &previous);
		SDL_GetRenderDrawColor(renderer, &rgba[0], &rgba[1], &rgba[2], &rgba[3]);
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(renderer, r, g, b, a);

		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
		SDL_RenderFillRect(renderer, &rect);

		// Restore blend mode.
		SDL_SetRenderDrawBlendMode(renderer, previous);
		SDL_SetRenderDrawColor(renderer, rgba[0], rgba[1], rgba[2], rgba[3]);

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
}
