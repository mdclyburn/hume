#include "Image.h"

namespace hm
{
	Image::Image()
	{
		
	}

	Image::Image(std::string filename, SDL_Renderer* renderer)
	{
		loadImage(filename, renderer);
	}
	
	Image::~Image()
	{
		
	}

	void Image::loadImage(std::string filename, SDL_Renderer* renderer)
	{
		// Unload a previous image.
		if(texture != nullptr)
		{
			SDL_DestroyTexture(texture);
			texture = nullptr;
		}

		SDL_Surface* surface = IMG_Load(filename.c_str());
		
		// Check if it was loaded.
		if(surface == NULL)
		{
			std::cout << "Could not open image: " << filename << std::endl;
			return;
		}
		
		// Color key surface
		Uint32 key = SDL_MapRGB(surface->format, 0xFF, 0x00, 0xFF);
		SDL_SetColorKey(surface, SDL_TRUE, key);
		
		// Convert to texture.
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		surface = nullptr;
		
		// Get dimensions.
		SDL_QueryTexture(texture, nullptr, nullptr, &info.w, &info.h);

		return;
	}

	void Image::setColorKey(Uint8 r, Uint8 g, Uint8 b)
	{
		color_key = { r, g, b, 0 };
		return;
	}
}
