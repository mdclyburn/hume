// Hume Library Version 0.6

#include "Image.h"

namespace hm
{
	Image::Image()
	{
		
	}

	Image::Image(std::string filename, SDL_Renderer* renderer)
	{
		open(filename, renderer);
	}
	
	Image::~Image()
	{
		
	}

	void Image::open(std::string filename, SDL_Renderer* renderer)
	{
		// Unload a previous image.
		if(texture != nullptr)
			close();

		SDL_Surface* surface = IMG_Load(filename.c_str());
		
		// Check if it was loaded.
		if(surface == NULL)
		{
			hm::Logger::log("Failed to open " + filename + ": " + IMG_GetError() + ".", hm::ERROR);
			return;
		}
		
		// Color key surface
		Uint32 key = SDL_MapRGB(surface->format, 0xFF, 0x00, 0xFF);
		SDL_SetColorKey(surface, SDL_TRUE, key);
		
		// Convert to texture.
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		surface = nullptr;
		if(texture == nullptr)
		{
			hm::Logger::log("Failed to convert surface of " + filename + " to texture.", hm::ERROR);
			return;
		}
		
		// Get dimensions.
		SDL_QueryTexture(texture, nullptr, nullptr, &info.w, &info.h);

		return;
	}
	
	void Image::close()
	{
		destroy();
		return;
	}

	void Image::setColorKey(Uint8 r, Uint8 g, Uint8 b)
	{
		color_key = { r, g, b, 0 };
		return;
	}
}
