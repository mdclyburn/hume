// Hume Library Version 0.6

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
		
		void open(const std::string& filename);
		void close();
		
		void play() const;
		void play(const int loops) const;
		void pause() const;
		void resume() const;
		void stop() const;
		
		void setFadeIn(const int ms);
		void setVolume(const int v);
		
	protected:
		int fadein;
		Mix_Music* music;
	};
}

#endif
