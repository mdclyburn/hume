#include "Tile.h"

namespace hm
{
	Tile::Tile() : index(0x00)
	{
		
	}
	
	Tile::Tile(std::string filename, char index, SDL_Renderer* renderer) : index(0)
	{
		load(filename, renderer);
		setIndex(index);
	}
	
	Tile::~Tile()
	{
		if(texture)
			SDL_DestroyTexture(texture);
		texture = nullptr;
	}
	
	void Tile::load(std::string filename, SDL_Renderer* renderer)
	{
		if(texture)
		{
			SDL_DestroyTexture(texture);
			texture = nullptr;
		}
		
		SDL_Surface* surface = IMG_Load(filename.c_str());
		assert(surface != nullptr);
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		assert(texture != nullptr);
		SDL_FreeSurface(surface);
		surface = nullptr;
		SDL_QueryTexture(texture, nullptr, nullptr, &info.w, &info.h);
		
		return;
	}
	
	void Tile::setIndex(char index)
	{
		this->index = index;
		return;
	}
	
	char Tile::getIndex()
	{
		return index;
	}
}