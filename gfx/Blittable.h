#ifndef BLITTABLE_H
#define BLITTABLE_H

#include <cassert>

#include "SDL2/SDL.h"

class Blittable
{
public:
    Blittable();
    virtual ~Blittable();

    void set_alpha(const Uint8 a);
    void modify_alpha(const short m);
    Uint8 get_alpha() const;

    unsigned int get_width() const;
    unsigned int get_height() const;

    SDL_Texture* get_texture() const;
    void destroy();

protected:
    SDL_Rect info;
    SDL_Texture* texture;
};

#endif
