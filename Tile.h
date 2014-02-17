#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>
#include <cassert>

#include <SDL2_image/SDL_image.h>

namespace hm
{
	class Tile
	{
	public:
		Tile();
		Tile(std::string filename, char index, SDL_Renderer* renderer);
		~Tile();
		
		void load(std::string filename, SDL_Renderer* renderer);
		void setIndex(char index);
		char getIndex();
		SDL_Texture* getTexture();
		
	protected:
		SDL_Texture* texture;
		char index;
	};
}

#endif
