#include "Text.h"

namespace hm
{
	Text::Text()
	{
		text = "Hume Library";
		setColor(0, 0, 0);
        setbgColor(0, 0, 0);
        setPosition(0, 0);
	}

	Text::Text(std::string text, Font& font)
	{
		this->text = text;
		setText(text, font);
		setColor(0, 0, 0);
        setColor(0, 0, 0);
        setPosition(0, 0);
	}

	SDL_Surface* Text::getSurface()
	{
		return sdltext;
	}

	void Text::setText(std::string text, Font& font)
	{
        std::cout << "Font: " << font.getFont() << std::endl;
        std::cout << "RM: " << font.getRenderMode() << std::endl;
		this->text = text;

		// Check for font.
		if(font.getFont() == NULL)
		{
			std::cout << "Can't set text. Font is NULL." << std::endl;
			return;
		}

        // Changes depending on the rendering mode.
        switch(font.getRenderMode())
        {
        case SOLID:
            std::cout << "Rendering solid text..." << std::endl;
            sdltext = TTF_RenderText_Solid(font.getFont(), text.c_str(), color);
            break;
        case SHADED:
            sdltext = TTF_RenderText_Shaded(font.getFont(), text.c_str(), color, bgcolor);
            break;
        case BLENDED:
            sdltext = TTF_RenderText_Blended(font.getFont(), text.c_str(), color);
            break;
        default:
            std::cout << "Text not rendered." << std::endl;
            break;
        }

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

    void Text::setbgColor(Uint8 r, Uint8 g, Uint8 b)
    {
        bgcolor.r = r;
        bgcolor.g = g;
        bgcolor.b = b;
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
        std::cout << "INFORMATION" << std::endl;
        std::cout << "Surface: " << sdltext << std::endl;
        std::cout << "Text: " << text << std::endl;
        std::cout << "Position: " << position.x << ", " << position.y << std::endl;

		return &position;
	}
}
