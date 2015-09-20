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

#include "Music.h"

Music::Music() : Audio(), fade_in(0), music(nullptr)
{
}

Music::~Music()
{
	if(music) close();
}

void Music::open(const std::string& file_name)
{
    music = Mix_LoadMUS(file_name.c_str());
    assert(music);
    return;
}

void Music::close()
{
    Mix_FreeMusic(music);
    music = nullptr;
    return;
}

void Music::play()
{
    play(0);
    return;
}

void Music::play(const unsigned int loops)
{
    Mix_FadeInMusic(music, loops, fade_in);
    return;
}

void Music::pause()
{
    Mix_PauseMusic();
    return;
}

void Music::resume()
{
    Mix_ResumeMusic();
    return;
}

void Music::stop()
{
    Mix_HaltMusic();
    return;
}

void Music::set_fade_in(const unsigned int ms)
{
    this->fade_in = ms;
    return;
}

void Music::set_volume(const unsigned int volume)
{
    // convert volume value to scale of 1 - 128
    float mixer_volume = ceilf(volume * 1.28);
    Mix_VolumeMusic(int(mixer_volume));
    return;
}
