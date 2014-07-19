//
//  Music.cpp
//  Hume
//
//  Created by Marshall Clyburn on 7/19/14.
//  Copyright (c) 2014 Marshall Clyburn. All rights reserved.
//

#include "Music.h"

namespace hm
{
	Music::Music() : Audio(), music(nullptr)
	{
		
	}
	
	Music::~Music()
	{
		close();
	}
	
	void Music::open(std::string filename)
	{
		// Close music if it's open.
		close();
		
		music = Mix_LoadMUS(filename.c_str());
		if(music == nullptr)
		{
			Logger::log("Failed to open " + filename + ".");
			Logger::log(Mix_GetError());
		}
		return;
	}
	
	void Music::close()
	{
		if(music != nullptr)
		{
			Mix_FreeMusic(music);
			music = nullptr;
		}
		return;
	}
	
	void Music::play()
	{
		play(0);
		
		return;
	}
	
	void Music::play(int loops)
	{
		if(music == nullptr)
		{
			Logger::log("Music has not been loaded.", hm::ERROR);
			return;
		}
		
		Mix_PlayMusic(music, loops);
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
	
	void Music::setVolume(int v)
	{
		// Clamp values.
		if(v < 0)
			volume = 0;
		else if(v > 100)
			volume = 100;
		else
			volume = v;
		
		// Convert volume value to scale of 1 - 128.
		float mixer_volume = ceilf(volume * 1.28);
		hm::Logger::log("Setting chunk volume to " + std::to_string(volume) + " (" + std::to_string(int(mixer_volume)) + ")" + ".");
		Mix_VolumeMusic(int(mixer_volume));
		return;
	}
}
