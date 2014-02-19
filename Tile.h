#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>
#include <cassert>

#include <SDL2_image/SDL_image.h>

#include "Blittable.h"

namespace hm
{
	class Tile : public Blittable
	{
	public:
		Tile();
		Tile(std::string filename, char index, SDL_Renderer* renderer);
		~Tile();
		
		void load(std::string filename, SDL_Renderer* renderer);
		void setIndex(char index);
		char getIndex();
		
	protected:
		char index;
	};
}

#endif
