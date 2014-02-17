#include "TileMap.h"

namespace hm
{
	TileMap::TileMap() : width(0), height(0), map(nullptr)
	{
		
	}
	
	TileMap::~TileMap()
	{
		if(map)
		{
			for(int i = 0; i < height; i++)
			{
				delete map[i];
			}
			delete map;
			map = nullptr;
		}
		
		while(!tiles.empty())
		{
			delete tiles.back();
			tiles.pop_back();
		}
	}
	
	void TileMap::setWidth(int width)
	{
		this->width = width;
		return;
	}
	
	void TileMap::setHeight(int height)
	{
		this->height = height;
		return;
	}
	
	SDL_Rect TileMap::getDimensions()
	{
		SDL_Rect r;
		r.w = width;
		r.h = height;
		return r;
	}
	
	void TileMap::addTile(Tile* tile)
	{
		for(int i = 0; i < tiles.size(); i++)
			assert(tiles[i]->getIndex() != tile->getIndex());
		tiles.push_back(tile);
		return;
	}
	
	Tile* TileMap::getTile(char index)
	{
		for(int i = 0; i < tiles.size(); i++)
			if(tiles[i]->getIndex() == index)
				return tiles[i];
		return nullptr;
	}
}
