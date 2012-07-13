#include "Text.h"

namespace hm
{
	Text::Text()
	{
        text = "Hume Library";
        setPosition(0, 0);
	}

	Text::Text(std::string text, Font& font)
	{
		this->text = text;
        sdltext = NULL;
        setText(text, font);
        setPosition(0, 0);
	}

    Text::~Text()
    {
        if(sdltext != NULL)
        {
            SDL_FreeSurface(sdltext);
            sdltext = NULL;
        }
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

		RenderMode rm = font.getRenderMode();
        if(rm == SOLID)
            sdltext = TTF_RenderText_Solid(font.getFont(), text.c_str(), font.getColor());
        if(rm == SHADED)
            sdltext = TTF_RenderText_Shaded(font.getFont(), text.c_str(), font.getColor(), font.getbColor());
        if(rm == BLENDED)
			sdltext = TTF_RenderText_Blended(font.getFont(), text.c_str(), font.getColor());
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

    void Text::optimize()
    {
        SDL_Surface* unoptimizedText = sdltext;
        sdltext = SDL_DisplayFormat(unoptimizedText);
        SDL_FreeSurface(unoptimizedText);

        return;
    }
}
