//
//  Sound.h
//  Hume
//
//  Created by Marshall Clyburn on 7/19/14.
//  Copyright (c) 2014 Marshall Clyburn. All rights reserved.
//

#ifndef SOUND_H
#define SOUND_H

#include <string>

#include "SDL2/SDL_mixer.h"

#include "Logger.h"

namespace hm
{
	class Sound
	{
	public:
		Sound();
		~Sound();
		
		void open(std::string filename);
		void close();
		
		void play();
		
		void setVolume(int v);
		int getVolume();
		
	protected:
		int volume;
		
		Mix_Chunk* chunk;
	};
}

#endif
