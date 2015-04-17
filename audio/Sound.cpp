#include "Sound.h"

Sound::Sound() : Audio(), chunk(nullptr)
{
}

Sound::~Sound()
{
    if(chunk) close();
}

void Sound::open(const std::string& file_name)
{
    chunk = Mix_LoadWAV(file_name.c_str());
    assert(chunk);
    return;
}

void Sound::close()
{
    Mix_FreeChunk(chunk);
    chunk = nullptr;

    return;
}

void Sound::play()
{
    assert(chunk);
    Mix_PlayChannel(-1, chunk, 0);

    return;
}

void Sound::set_volume(const unsigned int v)
{
    volume = v;

    // convert volume value to scale of 1 - 128.
    float mixer_volume = ceilf(volume * 1.28);
    Mix_VolumeChunk(chunk, int(mixer_volume));

    return;
}
