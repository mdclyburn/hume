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
	}
	
	Text::~Text()
	{
        
	}
	
	void Text::setFont(Font* font)
	{
		this->font = font;
		return;
	}
	
	void Text::setText(std::string text, SDL_Renderer* r)
	{
		this->text = text;
		render(r);
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
	
	void Text::setbColor(Uint8 r, Uint8 g, Uint8 b)
	{
		bcolor.r = r;
		bcolor.g = g;
		bcolor.b = b;
		
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
	
	void Text::render(SDL_Renderer* r)
	{
		// No rendering if no renderer.
		if(r == nullptr)
			return;
		// Check for font.
		if(font->getFont() == nullptr)
		{
			std::cout << "Cannot render. Font is NULL." << std::endl;
			return;
		}
		
		// Free previous texture
		if(texture != nullptr)
			SDL_DestroyTexture(texture);
		SDL_Surface* surface = nullptr;
		RenderMode rm = font->getRenderMode();
		if(rm == SOLID)
			surface = TTF_RenderText_Solid(font->getFont(), text.c_str(), color);
		if(rm == SHADED)
			surface = TTF_RenderText_Shaded(font->getFont(), text.c_str(), color, bcolor);
		if(rm == BLENDED)
			surface = TTF_RenderText_Blended(font->getFont(), text.c_str(), color);
		if(surface != nullptr)
			texture = SDL_CreateTextureFromSurface(r, surface);
		else
			std::cout << "Texture creation failed." << std::endl;
		
		// Update info
		SDL_QueryTexture(texture, nullptr, nullptr, &info.w, &info.h);
		return;
	}
}
