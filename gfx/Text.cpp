#include "Text.h"

Text::Text() : Blittable(), font(nullptr), text("")
{
    color.r = color.g = color.b = 255;
    bg_color.r = bg_color.g = bg_color.b = 0;
}

Text::~Text()
{
}

void Text::set_font(Font* const font)
{
    this->font = font;
    return;
}

void Text::set_text(const std::string& text, SDL_Renderer* r)
{
    assert(r);

    destroy();

    SDL_Surface* surface = nullptr;
    RenderMode rm = font->get_render_mode();
    if(rm == RenderMode::Solid)
	surface = TTF_RenderText_Solid(font->get_font(), text.c_str(), color);
    else if(rm == RenderMode::Shaded)
	surface = TTF_RenderText_Shaded(font->get_font(), text.c_str(), color, bg_color);
    else
	surface = TTF_RenderText_Blended(font->get_font(), text.c_str(), color);
    assert(surface);

    texture = SDL_CreateTextureFromSurface(r, surface);
    assert(texture);
    SDL_QueryTexture(texture, nullptr, nullptr, &info.w, &info.w);

    return;
}

std::string Text::get_text()
{
    return text;
}

void Text::set_color(const Uint8 r, const Uint8 g, const Uint8 b)
{
    color.r = r;
    color.g = g;
    color.b = b;

    return;
}

void Text::set_bg_color(const Uint8 r, const Uint8 g, const Uint8 b)
{
    bg_color.r = r;
    bg_color.g = g;
    bg_color.b = b;

    return;
}
