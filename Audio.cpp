// Hume Library Version 0.5

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
