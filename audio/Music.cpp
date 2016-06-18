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
    if(!music) throw SDLMixerException("No music loaded. Cannot play anything.");

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
    const int res = Mix_FadeInMusic(music, loops, fade_in);
	if(res) throw SDLMixerException();
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

bool Music::is_open() const
{
	if(music)
	{
		return true;
	}

	return false;
}
