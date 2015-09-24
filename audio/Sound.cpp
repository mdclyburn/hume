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
    assert(chunk);
    Mix_PlayChannel(-1, chunk, 0);

    return;
}

void Sound::set_volume(const unsigned int v)
{
    volume = v;

    // convert volume value to scale of 1 - 128.
    float mixer_volume = ceilf(volume * 1.28);
    Mix_VolumeChunk(chunk, int(mixer_volume));

    return;
}

Mix_Chunk* Sound::get_sound() const
{
	return chunk;
}
