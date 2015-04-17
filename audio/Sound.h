#ifndef SOUND_H
#define SOUND_H

#include "Audio.h"

class Sound : public Audio
{
public:
    Sound();
    virtual ~Sound();

    void open(const std::string& file_name);
    void close();

    void play();

    void set_volume(const unsigned int v);

protected:
    Mix_Chunk* chunk;
};

#endif
