#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "Blittable.h"

namespace hm
{
	class Image : public Blittable
	{
	public:
		Image(); // Constructor without loading image.
		Image(std::string filename, SDL_Renderer* renderer); // Constructor with image loading.

		void loadImage(std::string filename, SDL_Renderer* renderer); // Loads an image.

		SDL_Rect getDimensions();
		int getWidth();
		int getHeight();
		
		void setColorKey(Uint8 r, Uint8 g, Uint8 b); // Sets the color key.

	protected:
		int width;
		int height;
		SDL_Color color_key; // Color used for color keying.
	};
};

#endif
