#include "Text.h"

namespace hm
{
	Text::Text()
	{
		// Initialize.
		font = NULL;
		sdltext = NULL;
		text = "Hume Library";
	}

	Text::Text(Font *font)
	{
		// Initialize and set default text.
		this->font = font;
		sdltext = NULL;
		text = "Hume Library";
		updateSurface();
	}

	Text::Text(std::string text, Font *font)
	{
		// Initialize and set custom text.
		this->font = font;
		sdltext = NULL;
		this->text = text;
		updateSurface();
	}

	SDL_Surface* Text::getSurface()
	{
		return sdltext;
	}

	void Text::setText(std::string text)
	{
		this->text = text;
		updateSurface();
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

	void Text::updateSurface()
	{
		// First check if the font is null.
		if(font == NULL)
		{
			std::cout << "Cannot update surface. Font is nulled." << std::endl;
			return;
		}

		if(font->getRenderMode() == SOLID)
			sdltext = TTF_RenderText_Solid(font->getFont(), text.c_str(), *font->getFgColor());
		if(font->getRenderMode() == SHADED)
			sdltext = TTF_RenderText_Shaded(font->getFont(), text.c_str(), *font->getFgColor(), *font->getBgColor());
		if(font->getRenderMode() == BLENDED)
			sdltext = TTF_RenderText_Blended(font->getFont(), text.c_str(), *font->getFgColor());

		return;
	}
}
