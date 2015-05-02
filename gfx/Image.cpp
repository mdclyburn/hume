#include "Image.h"

Image::Image() : Blittable()
{
    color_key.r = 255;
    color_key.g = 0;
    color_key.b = 255;
}

Image::Image(const Uint8 r, const Uint8 g, const Uint8 b) : Blittable()
{
    color_key.r = r;
    color_key.g = g;
    color_key.b = b;
}

Image::~Image()
{
}

void Image::open(const std::string& filename, SDL_Renderer* const renderer)
{
    SDL_Surface* surface = IMG_Load(filename.c_str());
    assert(surface);

    // apply color keying
    const Uint32 key = SDL_MapRGB(surface->format, color_key.r, color_key.g, color_key.b);
    SDL_SetColorKey(surface, SDL_TRUE, key);

    // convert to texture
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    assert(texture);
    SDL_FreeSurface(surface);

    // get dimensions
    SDL_QueryTexture(texture, nullptr, nullptr, &info.w, &info.h);

    return;
}

void Image::close()
{
    destroy();
    return;
}
