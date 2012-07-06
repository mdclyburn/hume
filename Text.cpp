#include "Text.h"

namespace hm
{
	Text::Text()
	{
		// Initialize.
		font = NULL;
		sdltext = NULL;
		text = "Hume Library";
        setfColor(0, 0, 0);
        setbColor(0, 0, 0);
	}

	Text::Text(Font *font)
	{
		// Initialize and set default text.
		this->font = font;
		sdltext = NULL;
		text = "Hume Library";
		std::cout << "constructor invoked and calling updateSurface()" << std::endl;
        setfColor(0, 0, 0);
        setbColor(0, 0, 0);
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

    void Text::setfColor(Uint8 r, Uint8 g, Uint8 b)
    {
        fcolor.r = r;
        fcolor.g = g;
        fcolor.b = b;

        return;
    }

    SDL_Color Text::getfColor()
    {
        return fcolor;
    }

    void Text::setbColor(Uint8 r, Uint8 g, Uint8 b)
    {
        bcolor.r = r;
        bcolor.g = g;
        bcolor.b = b;

        return;
    }

    SDL_Color Text::getbColor()
    {
        return bcolor;
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

		// Check if the font is null.
		if(font == NULL)
		{
			std::cout << "Cannot update surface. Font is nulled." << std::endl;
			return;
		}

		if(font->getRenderMode() == SOLID)
		{
			std::cout << "Rendering text solid..." << std::endl;
            sdltext = TTF_RenderText_Solid(font->getFont(), text.c_str(), fcolor);
		}
		if(font->getRenderMode() == SHADED)
		{
			std::cout << "Rendering text shaded..." << std::endl;
            sdltext = TTF_RenderText_Shaded(font->getFont(), text.c_str(), fcolor, bcolor);
		}
		if(font->getRenderMode() == BLENDED)
		{
			std::cout << "Rendering text blended..." << std::endl;
            sdltext = TTF_RenderText_Blended(font->getFont(), text.c_str(), fcolor);
		}

		std::cout << "Surface is located at " << sdltext << "." << std::endl;

		return;
	}
}
