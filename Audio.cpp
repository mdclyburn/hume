// Hume Library Version 0.6

#include "Audio.h"

namespace hm
{
	Audio::Audio() : volume(100)
	{
		
	}
	
	Audio::~Audio()
	{
		
	}
	
	int Audio::getVolume() const
	{
		return volume;
	}
}
