#include "Blittable.h"

Blittable::Blittable() : texture(nullptr)
{
}

Blittable::~Blittable()
{
    if(texture) destroy();
}

void Blittable::set_alpha(const Uint8 a)
{
    SDL_SetTextureAlphaMod(texture, a);
    return;
}

void Blittable::modify_alpha(const short m)
{
    Uint8 current;
    const int res = SDL_GetTextureAlphaMod(texture, &current);
    SDL_SetTextureAlphaMod(texture, current + m);

    return;
}

Uint8 Blittable::get_alpha() const
{
    Uint8 current;
    const int res = SDL_GetTextureAlphaMod(texture, &current);
    assert(res);

    return current;
}

unsigned int Blittable::get_width() const
{
    return info.w;
}

unsigned int Blittable::get_height() const
{
    return info.h;
}

SDL_Texture* Blittable::get_texture() const
{
    return texture;
}

void Blittable::destroy()
{
    SDL_DestroyTexture(texture);
    texture = nullptr;

    return;
}
