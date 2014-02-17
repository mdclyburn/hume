#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <cassert>
#include <vector>

#include "Tile.h"

namespace hm
{
	class TileMap
	{
	public:
		TileMap();
		~TileMap();
		
		void setWidth(int width);
		void setHeight(int height);
		void init();
		SDL_Rect getDimensions();
		
		void addTile(Tile* tile);
		Tile* getTile(char index);
		
	protected:
		int width;
		int height;
		std::vector<Tile*> tiles;
		char** map;
	};
}

#endif
