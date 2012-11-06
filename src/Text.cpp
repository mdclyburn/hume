#include "Text.h"

namespace hm
{
	Text::Text() : font(NULL), text("Hume Library")
	{
		// Set color without calling setColor functions.
        color.r = 255;
		color.g = 255;
		color.b = 255;
		bcolor.r = 0;
		bcolor.g = 0;
		bcolor.b = 0;
	}

	Text::Text(std::string text, Font* font) : font(font), text(text)
	{
		color.r = 255;
		color.g = 255;
		color.b = 255;
		bcolor.r = 255;
		bcolor.g = 255;
		bcolor.b = 255;

        setText(text, font);
	}

    Text::~Text()
    {
        
    }

	SDL_Surface* Text::getSurface()
    {
		return surface;
	}

	void Text::setFont(Font* font)
	{
		this->font = font;
		setText(text, font);
		return;
	}

	void Text::setText(std::string text, Font* font)
	{
		this->text = text;
		this->font = font;

		// Check for font.
		if(font->getFont() == NULL)
		{
			std::cout << "Can't set text. Font is NULL." << std::endl;
			return;
        }

		// Free the previous surface.
		SDL_FreeSurface(surface);

		RenderMode rm = font->getRenderMode();
        if(rm == SOLID)
            surface = TTF_RenderText_Solid(font->getFont(), text.c_str(), color);
        if(rm == SHADED)
            surface = TTF_RenderText_Shaded(font->getFont(), text.c_str(), color, bcolor);
        if(rm == BLENDED)
			surface = TTF_RenderText_Blended(font->getFont(), text.c_str(), color);
        optimize();

		return;
	}

	std::string Text::getText()
	{
		return text;
    }

	void Text::setColor(Uint8 r, Uint8 g, Uint8 b)
	{
		color.r = r;
		color.g = g;
		color.b = b;
		setText(text, font);

		return;
	}

	void Text::setbColor(Uint8 r, Uint8 g, Uint8 b)
	{
		bcolor.r = r;
		bcolor.g = g;
		bcolor.b = b;
		setText(text, font);

		return;
	}

	SDL_Color Text::getColor()
	{
		return color;
	}

	SDL_Color Text::getbColor()
	{
		return bcolor;
	}
}
