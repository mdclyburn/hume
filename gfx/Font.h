#ifndef FONT_H
#define FONT_H

#include <cassert>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "RenderMode.h"

class Font
{
public:
    Font();
    virtual ~Font();

    void open(const std::string& file_name, const unsigned int pt_size);
    void close();

    void set_size(const unsigned int pt_size);

    void set_render_mode(const RenderMode& render_mode);
    RenderMode get_render_mode();

    TTF_Font* get_font();

protected:
    TTF_Font* font;
    std::string file_name;
    RenderMode render_mode;
};

#endif
