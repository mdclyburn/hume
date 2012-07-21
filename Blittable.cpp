#include "Blittable.h"

namespace hm
{
	Blittable::Blittable() : surface(NULL), alpha(255)
	{
		setPosition(0, 0);
	}

	Blittable::~Blittable()
	{
		SDL_FreeSurface(surface);
		surface = NULL;
	}

	SDL_Surface* Blittable::getSurface()
	{
		return surface;
	}

	void Blittable::freeSurface()
	{
		if(surface != NULL)
		{
			SDL_FreeSurface(surface);
			surface = NULL;
		}

		return;
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

	void Blittable::setAlpha(Uint8 alpha)
	{
		if(alpha > 255)
			alpha = 255;
		if(alpha < 0)
			alpha = 0;
		else
			this->alpha = alpha;
		SDL_SetAlpha(surface, SDL_SRCALPHA, alpha);

		return;
	}

	Uint8 Blittable::getAlpha()
	{
		return alpha;
	}

	void Blittable::optimize()
	{
		SDL_Surface* unoptimizedSurface = surface;
		surface = SDL_DisplayFormat(unoptimizedSurface);

		// If our optimized surface is NULL.
		if(surface == NULL)
		{
			// Set us back.
			surface = unoptimizedSurface;
			std::cout << "Could not optimize surface." << std::endl;
		}
		else
			SDL_FreeSurface(unoptimizedSurface);

		return;
	}
}