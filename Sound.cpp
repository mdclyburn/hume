// Hume Library Version 0.4.3

#include "Sound.h"

namespace hm
{
	Sound::Sound() : chunk(nullptr)
	{
		
	}
	
	Sound::~Sound()
	{
		close();
	}
	
	void Sound::open(std::string filename)
	{
		// Close chunk if there is one loaded.
		close();
		
		chunk = Mix_LoadWAV(filename.c_str());
		if(chunk == nullptr)
		{
			Logger::log("Failed to load " + filename + ".");
			Logger::log(Mix_GetError());
		}
		return;
	}
	
	void Sound::close()
	{
		if(chunk != nullptr)
		{
			Mix_FreeChunk(chunk);
			chunk = nullptr;
		}
		
		return;
	}
	
	void Sound::play()
	{
		Mix_PlayChannel(-1, chunk, 0);
		return;
	}
	
	void Sound::setVolume(int v)
	{
		// Clamp values.
		if(volume < 0)
			volume = 0;
		else if(volume > 100)
			volume = 100;
		volume = v;
		
		// Convert volume value to scale of 1 - 128.
		float mixer_volume = ceilf(volume * 1.28);
		hm::Logger::log("Setting chunk volume to " + std::to_string(volume) + " (" + std::to_string(int(mixer_volume)) + ")" + ".");
		Mix_VolumeChunk(chunk, int(mixer_volume));
		return;
	}
	
	int Sound::getVolume()
	{
		return volume;
	}
}
