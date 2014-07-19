// Hume Library Version 0.4.3

#ifndef MUSIC_H
#define MUSIC_H

#include "Audio.h"

namespace hm
{
	class Music : Audio
	{
	public:
		Music();
		virtual ~Music();
		
		void open(std::string filename);
		void close();
		
		void play();
		
		void setVolume(int v);
		
	protected:
		Mix_Music* music;
	};
}

#endif
