// Hume Library Version 0.6

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
		
		void play() const;
		
		void setVolume(int v);
		
	protected:
		Mix_Chunk* chunk;
	};
}

#endif
