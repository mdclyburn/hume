#include "Text.h"

namespace hm
{
	Text::Text()
	{
		text = "Hume Library";
		setColor(0, 0, 0);
	}

	Text::Text(std::string text, Font& font)
	{
		this->text = text;
		setText(text, font);
		setColor(0, 0, 0);
	}

	SDL_Surface* Text::getSurface()
	{
		return sdltext;
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

		sdltext = TTF_RenderText_Solid(font.getFont(), text.c_str(), color);
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
		return;
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
