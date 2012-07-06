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
		std::cout << "constructor invoked and calling updateSurface()" << std::endl;
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
		// See if TTF_WasInit().
		if(TTF_WasInit() == 0)
		{
			std::cout << "SDL_ttf was not initialized. Cannot update surface." << std::endl;
			return;
		}
		else
			std::cout << "SDL_ttf was initialized. Continuing..." << std::endl;

		// Check if the font is null.
		if(font == NULL)
		{
			std::cout << "Cannot update surface. Font is nulled." << std::endl;
			return;
		}

		// Output.
		std::cout << "Font: " << font << std::endl;
		std::cout << "Text: " << text.c_str() << std::endl;
		std::cout << "FGColor: " << font->getFgColor().r << ", " << font->getFgColor().g << ", " << font->getFgColor().b << std::endl;
		std::cout << "BGColor: " << font->getBgColor().r << ", " << font->getBgColor().g << ", " << font->getBgColor().b << std::endl;

		if(font->getRenderMode() == SOLID)
		{
			std::cout << "Rendering text solid..." << std::endl;
			sdltext = TTF_RenderText_Solid(font->getFont(), text.c_str(), font->getFgColor());
		}
		if(font->getRenderMode() == SHADED)
		{
			std::cout << "Rendering text shaded..." << std::endl;
			sdltext = TTF_RenderText_Shaded(font->getFont(), text.c_str(), font->getFgColor(), font->getBgColor());
		}
		if(font->getRenderMode() == BLENDED)
		{
			std::cout << "Rendering text blended..." << std::endl;
			sdltext = TTF_RenderText_Blended(font->getFont(), text.c_str(), font->getFgColor());
		}

		std::cout << "Surface is located at " << sdltext << "." << std::endl;

		return;
	}
}
