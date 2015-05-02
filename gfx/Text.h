// Hume Library Version 0.7

#ifndef TEXT_H
#define TEXT_H

#include <string>

#include <SDL2/SDL.h>

#include "Blittable.h"
#include "Font.h"

class Text : public Blittable
{
public:
    Text();
    virtual ~Text();

    void set_font(Font* const font);

    void set_text(const std::string& text, SDL_Renderer* r);
    std::string get_text();

    void set_color(const Uint8 r, const Uint8 g, const Uint8 b);
    void set_bg_color(const Uint8 r, const Uint8 g, const Uint8 b);

protected:
    Font* font;
    std::string text;
    SDL_Color color;
    SDL_Color bg_color;
};

#endif
