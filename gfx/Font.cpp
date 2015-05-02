#include "Font.h"

Font::Font() : font(nullptr), file_name(""), render_mode(RenderMode::Blended)
{
}

Font::~Font()
{
    if(font) close();
}

void Font::open(const std::string& file_name, const unsigned int pt_size)
{
    this->file_name = file_name;

    font = TTF_OpenFont(file_name.c_str(), pt_size);
    assert(font);

    return;
}

void Font::close()
{
    TTF_CloseFont(font);
    return;
}

void Font::set_size(const unsigned int pt_size)
{
    close();
    open(file_name, pt_size);

    return;
}

void Font::set_render_mode(const RenderMode& render_mode)
{
    this->render_mode = render_mode;
    return;
}

RenderMode Font::get_render_mode()
{
    return render_mode;
}

TTF_Font* Font::get_font()
{
    return font;
}
