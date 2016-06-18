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

#include "Blittable.h"

namespace hume
{
	Blittable::Blittable() : texture(nullptr)
	{
	}

	Blittable::~Blittable()
	{
		if(texture) destroy();
	}

	void Blittable::set_alpha(const Uint8 a)
	{
		const int res = SDL_SetTextureAlphaMod(texture, a);
		if(res) throw SDLException();

		return;
	}

	void Blittable::modify_alpha(const short m)
	{
		Uint8 current;
		const int res = SDL_GetTextureAlphaMod(texture, &current);
		if(res) throw SDLException();
		SDL_SetTextureAlphaMod(texture, current + m);

		return;
	}

	Uint8 Blittable::get_alpha() const
	{
		Uint8 current;
		const int res = SDL_GetTextureAlphaMod(texture, &current);
		if(res) throw SDLException();

		return current;
	}

	unsigned int Blittable::get_width() const
	{
		return info.w;
	}

	unsigned int Blittable::get_height() const
	{
		return info.h;
	}

	SDL_Texture* Blittable::get_texture() const
	{
		return texture;
	}

	void Blittable::destroy()
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;

		return;
	}
}
