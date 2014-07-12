#include "Blittable.h"

namespace hm
{
	Blittable::Blittable() : alpha(255), texture(NULL)
	{
		setPosition(0, 0);
	}

	Blittable::~Blittable()
	{
		if(texture != nullptr)
			SDL_DestroyTexture(texture);
		texture = nullptr;
	}
	
	int Blittable::getAlpha()
	{
		return alpha;
	}
	
	void Blittable::setAlpha(int alphaValue)
	{
		if(alphaValue > 255)
			alphaValue = 255;
		else if(alphaValue < 0)
			alphaValue = 0;
		alpha = alphaValue;
		SDL_SetTextureAlphaMod(texture, alpha);
		
		return;
	}

	void Blittable::setPosition(int x, int y)
	{
		info.x = x;
		info.y = y;
		
		return;
	}

	SDL_Rect Blittable::getPosition()
	{
		
		return info;
	}
	
	void Blittable::move(int x, int y)
	{
		info.x += x;
		info.y += y;
		return;
	}
	
	void Blittable::setx(int x)
	{
		info.x = x;
		return;
	}
	
	void Blittable::sety(int y)
	{
		info.y = y;
		return;
	}
	
	SDL_Rect Blittable::getDimensions()
	{
		SDL_Rect sdlr;
		sdlr.w = info.w;
		sdlr.h = info.h;
		return sdlr;
	}
	
	int Blittable::getWidth()
	{
		return info.w;
	}
	
	int Blittable::getHeight()
	{
		return info.h;
	}
	
	SDL_Rect Blittable::getInfo()
	{
		return info;
	}
	
	SDL_Texture* Blittable::getTexture()
	{
		return texture;
	}
}
