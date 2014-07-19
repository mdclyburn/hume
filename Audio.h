// Hume Library Version 0.4.3

#ifndef AUDIO_H
#define AUDIO_H

#include <string>

#include "SDL2/SDL_mixer.h"

#include "Logger.h"

namespace hm
{
	class Audio
	{
	public:
		Audio();
		virtual ~Audio();
		
		virtual void open(std::string filename) = 0;
		virtual void close() = 0;
		
		virtual void play() = 0;
		
		virtual void setVolume(int v) = 0;
		virtual int getVolume();
		
	protected:
		int volume;
	};
}

#endif
