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

#include "Sound.h"

namespace hume
{
	Sound::Sound() : Audio(), chunk(nullptr)
	{
	}

	Sound::~Sound()
	{
		if(chunk) close();
	}

	void Sound::open(const std::string& file_name)
	{
		chunk = Mix_LoadWAV(file_name.c_str());
		if(!chunk) throw SDLMixerException();

		return;
	}

	void Sound::close()
	{
		Mix_FreeChunk(chunk);
		chunk = nullptr;

		return;
	}

	void Sound::play()
	{
		if(!chunk) throw SDLMixerException("No chunk loaded. Cannot play anything.");
		Mix_PlayChannel(-1, chunk, 0);

		return;
	}

	Mix_Chunk* Sound::get_sound() const
	{
		return chunk;
	}
}
