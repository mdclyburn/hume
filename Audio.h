// Hume Library Version 0.6

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
		
		virtual void open(const std::string& filename) = 0;
		virtual void close() = 0;
		
		virtual void play() const = 0;
		
		virtual void setVolume(const unsigned int v) = 0;
		virtual unsigned int getVolume() const;
		
	protected:
		unsigned int volume;
	};
}

#endif
