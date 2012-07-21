#include "Text.h"

namespace hm
{
	Text::Text() : text("Hume Library"), sdltext(NULL), alpha(255)
	{
        setPosition(0, 0);
	}

	Text::Text(std::string text, Font& font) : text(text), sdltext(NULL), alpha(255)
	{
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

		// Free the previous surface.
		SDL_FreeSurface(sdltext);

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

	void Text::setAlpha(int alpha)
	{
		if(alpha > 255)
			alpha = 255;
		if(alpha < 0)
			alpha = 0;
		else
			this->alpha = alpha;
		SDL_SetAlpha(sdltext, SDL_SRCALPHA, alpha);

		return;
	}

	int Text::getAlpha()
	{
		return alpha;
	}

    void Text::optimize()
    {
		if(sdltext == NULL)
			return;
        SDL_Surface* unoptimizedText = sdltext;
        sdltext = SDL_DisplayFormat(unoptimizedText);
        SDL_FreeSurface(unoptimizedText);

        return;
    }
}
