#include "Text.h"

namespace hm
{
	Text::Text() : text("Hume Library")
	{
        
	}

	Text::Text(std::string text, Font& font) : text(text)
	{
        setText(text, font);
	}

    Text::~Text()
    {
        
    }

	SDL_Surface* Text::getSurface()
    {
		return surface;
	}

	void Text::setText(std::string text, Font& font)
	{
		this->text = text;

		// Check for font.
		if(font.getFont() == NULL)
		{
			std::cout << "Can't set text. Font is NULL." << std::endl;
			return;
        }

		// Free the previous surface.
		SDL_FreeSurface(surface);

		RenderMode rm = font.getRenderMode();
        if(rm == SOLID)
            surface = TTF_RenderText_Solid(font.getFont(), text.c_str(), font.getColor());
        if(rm == SHADED)
            surface = TTF_RenderText_Shaded(font.getFont(), text.c_str(), font.getColor(), font.getbColor());
        if(rm == BLENDED)
			surface = TTF_RenderText_Blended(font.getFont(), text.c_str(), font.getColor());
        optimize();

		return;
	}

	std::string Text::getText()
	{
		return text;
    }

    void Text::setPosition(int x, int y)
    {
        position.x = x;
        position.y = y;
        return;
    }

	SDL_Rect* Text::getPosition()
    {
		return &position;
	}
}
