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
		draw_color.r = draw_color.g = draw_color.b = 0;
		draw_color.a = SDL_ALPHA_OPAQUE;
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

	void Graphics::set_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a)
	{
		draw_color.r = r;
		draw_color.g = g;
		draw_color.b = b;
		draw_color.a = a;

		if(SDL_SetRenderDrawColor(window->get_renderer(), r, g, b, a) != 0) throw SDLException();

		return;
	}

	void Graphics::set_color(const Color& color)
	{
		this->draw_color = color;
		if(SDL_SetRenderDrawColor(window->get_renderer(), color.r, color.g, color.b, color.a) != 0) throw SDLException();

		return;
	}

	Color Graphics::get_color() const
	{
		return draw_color;
	}

	void Graphics::set_use_alpha_blending(const bool b)
	{
		if(!window) throw Exception("No window or renderer available.");

		SDL_BlendMode blend_mode;
		if(b) blend_mode = SDL_BLENDMODE_BLEND;
		else blend_mode = SDL_BLENDMODE_NONE;

		if(SDL_SetRenderDrawBlendMode(window->get_renderer(), blend_mode) != 0) throw SDLException();

		return;
	}

	bool Graphics::get_use_alpha_blending() const
	{
		if(!window) throw Exception("No window or renderer available.");

		SDL_BlendMode blend_mode;
		if(SDL_GetRenderDrawBlendMode(window->get_renderer(), &blend_mode) != 0) throw SDLException();

		return (blend_mode == SDL_BLENDMODE_BLEND);
	}

	Image* Graphics::load_image(const std::string& filename)
	{
		Image* image = new Image();
		image->open(filename, window->get_renderer());

		return image;
	}

	Image* Graphics::load_image(const std::string& filename, const uint8_t r, const uint8_t g, const uint8_t b)
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

	void Graphics::draw_line(const int32_t x1, const int32_t y1, const int32_t x2, const int32_t y2)
	{
		if(SDL_RenderDrawLine(window->get_renderer(), x1, y1, x2, y2) != 0) throw SDLException();
		return;
	}

	void Graphics::draw_rect(const Properties& p)
	{
		draw_rect(p.x, p.y, p.w, p.h);
		return;
	}

	void Graphics::draw_rect(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h)
	{
		SDL_Renderer* const renderer = window->get_renderer();

		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
		if(SDL_RenderFillRect(renderer, &rect) != 0) throw SDLException();

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
