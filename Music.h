// Hume Library Version 0.5

#ifndef MUSIC_H
#define MUSIC_H

#include "Audio.h"

namespace hm
{
	const int LOOP_INIFINITELY = -1;
	
	class Music : Audio
	{
	public:
		Music();
		virtual ~Music();
		
		void open(std::string filename);
		void close();
		
		void play();
		void play(int loops);
		void pause();
		void resume();
		void stop();
		
		void setFadeIn(int ms);
		void setVolume(int v);
		
	protected:
		int fadein;
		Mix_Music* music;
	};
}

#endif
