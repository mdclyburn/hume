#include "Image.h"

namespace hm
{
	Image::Image()
	{
		
	}

	Image::Image(std::string filename)
	{
		loadImage(filename);
	}

	void Image::loadImage(std::string filename)
	{
		// Unload a previous image.
		freeSurface();

		surface = IMG_Load(filename.c_str());
		
		// Check if it was loaded.
		if(surface != NULL)
		{
			optimize(); // If it was, optimize it
			colorKey(); // and color key it.
		}

		return;
	}

	void Image::setColorKey(Uint8 r, Uint8 g, Uint8 b)
	{
		SDL_SetColorKey(surface, SDL_SRCCOLORKEY, SDL_MapRGB(surface->format, r, g, b));
		return;
	}

	void Image::colorKey()
	{
		Uint32 key = SDL_MapRGB(surface->format, 0xFF, 0x00, 0xFF);
		SDL_SetColorKey(surface, SDL_SRCCOLORKEY, key);
		return;
	}
};
