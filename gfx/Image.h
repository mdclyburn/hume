#ifndef IMAGE_H
#define IMAGE_H

#include <cassert>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Blittable.h"

class Image : public Blittable
{
public:
    Image();
    Image(const Uint8 r, const Uint8 g, const Uint8 b);
    virtual ~Image();

    virtual void open(const std::string& filename, SDL_Renderer* const renderer);
    virtual void close();

protected:
    SDL_Color color_key;
};

#endif
