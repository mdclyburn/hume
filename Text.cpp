#include "Text.h"

namespace hm
{
	Text::Text()
	{
		// Null pointers.
		font = NULL;
		sdltext = NULL;
		
		size = 12;
	}
	
	Text::Text(std::string text, int size)
	{
		this->text = text;
		this->size = size;
		font = NULL;
		sdltext = NULL;
	}
	
	Text::Text(TTF_Font* font, std::string text, int size)
	{
		this->font = font;
		this->text = text;
		this->size = size;
		
		// We have our font, text and size, so update the SDL_Surface.
		updateSurface();
	}
	
	void Text::setText(std::string text)
	{
		this->text = text;
		updateSurface();
		return;
	}
	
	std::string Text::getText()
	{
		return text;
	}
	
	void Text::setFont(TTF_Font* font)
	{
		this->font = font;
		updateSurface();
		return;
	}
	
	TTF_Font* Text::getFont()
	{
		return font;
	}
	
	void Text::setSize(int size)
	{
		this->size = size;
		updateSurface();
		return;
	}
	
	int Text::getSize()
	{
		return size;
	}
	
    SDL_Surface* Text::getSurface()
	{
		return sdltext;
	}
	
    void Text::setColor(int r, int g, int b)
	{
		color.r = r;
		color.g = g;
		color.b = b;
		updateSurface();
		
		return;
	}
	
    SDL_Color Text::getColor()
	{
		return color;
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
		// Check our resources.
		if(font == NULL || sdltext == NULL)
			return;
		sdltext = TTF_RenderText_Solid(font, text.c_str(), color);
		return;
	}
}
