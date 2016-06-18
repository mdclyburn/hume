/*
Hume Library
Copyright (C) 2015 Marshall Clyburn

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
USA
*/

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
	if(!font) throw SDLTTFException();

    return;
}

void Font::close()
{
    TTF_CloseFont(font);
	font = nullptr;
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
