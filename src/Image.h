#ifndef IMAGE_H
#define IMAGE_H

#include "Blittable.h"
#include <SDL/SDL.h>
#include <iostream>
#include <string>

#ifdef __APPLE__
#include <SDL_image/SDL_image.h>
#else
#include <SDL/SDL_image.h>
#endif

namespace hm
{
	class Image : public Blittable
	{
	public:
		Image(); // Constructor without loading image.
		Image(std::string filename); // Constructor with image loading.

		void loadImage(std::string filename); // Loads an image.

		void setColorKey(Uint8 r, Uint8 g, Uint8 b); // Sets the color key.

	protected:		
		void colorKey(); // Sets up the color key for transparency.
	};
};

#endif
