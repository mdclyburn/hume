//
//  Sound.h
//  Hume
//
//  Created by Marshall Clyburn on 7/19/14.
//  Copyright (c) 2014 Marshall Clyburn. All rights reserved.
//

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
