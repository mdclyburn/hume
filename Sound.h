// Hume Library Version 0.4.3

#ifndef SOUND_H
#define SOUND_H

#include "Audio.h"

namespace hm
{
	class Sound : public Audio
	{
	public:
		Sound();
		virtual ~Sound();
		
		void open(std::string filename);
		void close();
		
		void play();
		
		void setVolume(int v);
		
	protected:
		Mix_Chunk* chunk;
	};
}

#endif
