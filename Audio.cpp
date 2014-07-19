// Hume Library Version 0.4.3

#include "Audio.h"

namespace hm
{
	Audio::Audio() : volume(100)
	{
		
	}
	
	Audio::~Audio()
	{
		
	}
	
	int Audio::getVolume()
	{
		return volume;
	}
}
