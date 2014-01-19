#include "Blittable.h"

namespace hm
{
	Blittable::Blittable() : width(0), height(0), alpha(255), texture(NULL)
	{
		setPosition(0, 0);
	}

	Blittable::~Blittable()
	{
		if(texture != nullptr)
			SDL_DestroyTexture(texture);
		texture = nullptr;
	}

	SDL_Texture* Blittable::getTexture()
	{
		return texture;
	}

	void Blittable::setPosition(int x, int y)
	{
		position.x = x;
		position.y = y;
		
		return;
	}

	SDL_Rect* Blittable::getPosition()
	{
		return &position;
	}
	
	SDL_Rect Blittable::getDimensions()
	{
		SDL_Rect sdlr;
		sdlr.w = width;
		sdlr.h = height;
		return sdlr;
	}
	
	int Blittable::getWidth()
	{
		return width;
	}
	
	int Blittable::getHeight()
	{
		return height;
	}

	void Blittable::move(int x, int y)
	{
		position.x += x;
		position.y += y;
		return;
	}

	void Blittable::setx(int x)
	{
		position.x = x;
		return;
	}

	void Blittable::sety(int y)
	{
		position.y = y;
		return;
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

	int Blittable::getAlpha()
	{
		return alpha;
	}
}
