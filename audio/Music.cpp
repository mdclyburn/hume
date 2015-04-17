#include "Music.h"

Music::Music() : Audio(), fade_in(0), music(nullptr)
{
}

Music::~Music()
{
}

void Music::open(const std::string& file_name)
{
    music = Mix_LoadMUS(file_name.c_str());
    assert(music);
    return;
}

void Music::close()
{
    Mix_FreeMusic(music);
    music = nullptr;
    return;
}

void Music::play()
{
    play(0);
    return;
}

void Music::play(const unsigned int loops)
{
    Mix_FadeInMusic(music, loops, fade_in);
    return;
}

void Music::pause()
{
    Mix_PauseMusic();
    return;
}

void Music::resume()
{
    Mix_ResumeMusic();
    return;
}

void Music::stop()
{
    Mix_HaltMusic();
    return;
}

void Music::set_fade_in(const unsigned int ms)
{
    this->fade_in = ms;
    return;
}

void Music::set_volume(const unsigned int volume)
{
    // convert volume value to scale of 1 - 128
    float mixer_volume = ceilf(volume * 1.28);
    Mix_VolumeMusic(int(mixer_volume));
    return;
}
