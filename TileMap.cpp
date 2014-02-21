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
	
	void TileMap::init()
	{
		assert(map == nullptr);
		map = new Tile**[width];
		for(int i = 0; i < width; i++)
			map[i] = new Tile*[height];
	}
	
	void TileMap::loadMap(std::string filename)
	{
		FILE* file = fopen(filename.c_str(), "r");
		assert(file != nullptr);
		for(int y = 0; y < height; y++)
		{
			for(int x = 0; x < width; x++)
			{
				assert(!feof(file));
				int tile_index = 0;
				fscanf(file, "%i", &tile_index);
				assert(tile_index != 0);
				
				// Set the tile to the given index.
				assert(setTile(x, y, tile_index)); // Failed assert means tile not found.
			}
		}
		
		return;
	}
	
	SDL_Rect TileMap::getDimensions()
	{
		SDL_Rect r;
		r.w = width;
		r.h = height;
		return r;
	}
	
	SDL_Rect TileMap::getTileDimensions()
	{
		// All other tiles are assumed to have the same dimensions
		// as the first loaded tile.
		assert(tiles.size() > 0);
		return tiles[0]->getDimensions();
	}
	
	void TileMap::addTile(Tile* tile)
	{
		for(int i = 0; i < tiles.size(); i++)
			assert(tiles[i]->getIndex() != tile->getIndex());
		tiles.push_back(tile);
		return;
	}
	
	bool TileMap::setTile(int x, int y, int index)
	{
		Tile* tile_loc = nullptr;
		for(int i = 0; i < tiles.size(); i++)
		{
			if(tiles[i]->getIndex() == char(index))
			{
				tile_loc = tiles[i];
				map[x][y] = tile_loc;
			}
		}
		
		if(tile_loc == nullptr)
			return false;
		else
			return true;
	}
	
	Tile* TileMap::getTile(char index)
	{
		for(int i = 0; i < tiles.size(); i++)
			if(tiles[i]->getIndex() == index)
				return tiles[i];
		return nullptr;
	}
	
	Tile* TileMap::getTile(int x, int y)
	{
		assert(map != nullptr);
		return map[x][y];
	}
}
