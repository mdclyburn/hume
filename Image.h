#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Blittable.h"
#include "Logger.h"

namespace hm
{
	class Image : public Blittable
	{
	public:
		Image();
		Image(std::string filename, SDL_Renderer* renderer);
		~Image();

		virtual void loadImage(std::string filename, SDL_Renderer* renderer);
		
		void setColorKey(Uint8 r, Uint8 g, Uint8 b);

	protected:
		SDL_Color color_key;
	};
};

#endif
