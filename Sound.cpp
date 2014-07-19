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
}
