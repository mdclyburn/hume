// Hume Library Version 0.7

#ifndef AUDIO_H
#define AUDIO_H

#include <cassert>
#include <string>

#include <SDL2/SDL_mixer.h>

class Audio
{
public:
    Audio();
    virtual ~Audio();

    virtual void open(const std::string& file_name) = 0;
    virtual void close() = 0;

    virtual void play() = 0;

    virtual void set_volume(const unsigned int v) = 0;
    virtual unsigned int get_volume() const;

protected:
    unsigned int volume;
};

#endif
