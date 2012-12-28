/*
 * Sound.cpp
 *
 *  Created on: Nov 17, 2012
 *      Author: Marshall
 */

#include "Sound.h"
namespace hm
{
	Sound::Sound() : sound(NULL)
	{
		// Mix_OpenAudio should have been called by game
		// at this point in runtime.
	}

	Sound::Sound(std::string file) : sound(NULL)
	{
		if(!open(file))
			std::cout << "Failed to load " << file << std::endl;
	}

	Sound::~Sound()
	{
		Mix_FreeChunk(sound);
		sound = NULL;
	}

	void Sound::play()
	{
		if(sound == NULL)
			return;
		if(Mix_PlayChannel(-1, sound, 0) == -1)
			std::cout << "Failed to play sound." << std::endl;
		return;
	}

	bool Sound::open(std::string file)
	{
		sound = Mix_LoadWAV(file.c_str());
		if(sound == NULL)
			return false;
		return true;
	}

	void Sound::close()
	{
		Mix_FreeChunk(sound);
		sound = NULL;
		return;
	}

	void Sound::setVolume(int volume)
	{
		Mix_VolumeChunk(sound, (int)((double)volume * 1.28));
		std::cout << "Volume is now " << (int)((double)volume * 1.28);
		return;
	}
}
