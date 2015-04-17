#include "Audio.h"

Audio::Audio() : volume(100)
{
}

Audio::~Audio()
{
}

unsigned int Audio::get_volume() const
{
    return volume;
}
