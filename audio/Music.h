// Hume Library Version 0.7

#ifndef MUSIC_H
#define MUSIC_H

#include "Audio.h"

class Music : public Audio
{
    Music();
    virtual ~Music();

    void open(const std::string& file_name);
    void close();

    void play();
    void play(const unsigned int loops);
    void pause();
    void resume();
    void stop();

    void set_fade_in(const unsigned int ms);
    void set_volume(const unsigned int v);

protected:
    unsigned int fade_in;
    Mix_Music* music;
};

#endif
