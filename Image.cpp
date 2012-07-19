#include "Image.h"

namespace hm
{
	Image::Image()
	{
		image = NULL; // Null the pointer for safety.
		position.x = 0; // Zero position.
		position.y = 0;
	}

	Image::Image(std::string filename)
	{
		image = NULL; // Null the pointer for safety.
		loadImage(filename);
		position.x = 0;
		position.y = 0;
	}

	void Image::loadImage(std::string filename)
	{
		// Unload a previous image.
		deleteImage();

		image = IMG_Load(filename.c_str());
		
		// Check if it was loaded.
		if(image != NULL)
		{
			optimize(); // If it was, optimize it
			colorKey(); // and color key it.
		}

		return;
	}

	SDL_Surface* Image::getImage()
	{
		return image;
	}

	void Image::draw(SDL_Surface* surface)
	{
		SDL_BlitSurface(this->image, NULL, surface, this->getPosition());
		return;
	}

	void Image::setPosition(int x, int y)
	{
		position.x = x;
		position.y = y;
		return;
	}

	SDL_Rect* Image::getPosition()
	{
		return &position;
	}

	void Image::move(int x, int y)
	{
		position.x += x;
		position.y += y;
		return;
	}

	void Image::setx(int x)
	{
		this->position.x = x;
		return;
	}
	
	void Image::sety(int y)
	{
		this->position.y = y;
		return;
	}

	void Image::setColorKey(Uint8 r, Uint8 g, Uint8 b)
	{
		SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, r, g, b));
		return;
	}

	void Image::colorKey()
	{
		Uint32 key = SDL_MapRGB(image->format, 0xFF, 0x00, 0xFF);
		SDL_SetColorKey(image, SDL_SRCCOLORKEY, key);
		return;
	}
	void Image::optimize()
	{
		SDL_Surface* unoptimizedImage = image; // Temporary storage.
		image = SDL_DisplayFormat(unoptimizedImage);
		SDL_FreeSurface(unoptimizedImage);

		return;
	}

	void Image::deleteImage()
	{
		// If it isn't null, free the surface.
		if(image != NULL)
		{
			SDL_FreeSurface(image);
			image = NULL;
		}

		return;
	}
};
