// Hume Library Version 0.6

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
	
	unsigned int Blittable::getAlpha() const
	{
		return alpha;
	}
	
	void Blittable::setAlpha(unsigned int alphaValue)
	{
		if(alphaValue > 255)
			alphaValue = 255;
		alpha = alphaValue;
		SDL_SetTextureAlphaMod(texture, alpha);
		
		return;
	}
	
	void Blittable::modifyAlpha(int mod)
	{
		setAlpha(alpha + mod);
		return;
	}

	void Blittable::setPosition(int x, int y)
	{
		info.x = x;
		info.y = y;
		
		return;
	}

	SDL_Rect Blittable::getPosition() const
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
	
	SDL_Rect Blittable::getDimensions() const
	{
		SDL_Rect sdlr;
		sdlr.w = info.w;
		sdlr.h = info.h;
		return sdlr;
	}
	
	unsigned int Blittable::getWidth() const
	{
		return info.w;
	}
	
	unsigned int Blittable::getHeight() const
	{
		return info.h;
	}
	
	SDL_Rect Blittable::getInfo() const
	{
		return info;
	}
	
	SDL_Texture* Blittable::getTexture() const
	{
		return texture;
	}
	
	void Blittable::destroy()
	{
		if(texture != nullptr)
			SDL_DestroyTexture(texture);
		texture = nullptr;
		return;
	}
}
