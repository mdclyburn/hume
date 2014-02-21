//
//  Sprite.cpp
//  Game
//
//  Created by Marshall Clyburn on 12/30/13.
//  Copyright (c) 2013 Marshall Clyburn. All rights reserved.
//

#include "Sprite.h"

namespace hm
{
	Sprite::Sprite() : selected_column(0), selected_row(0)
	{
		input = output = { 0, 0, 0, 0 };
	}
	
	Sprite::~Sprite()
	{
		
	}
	
	void Sprite::loadImage(std::string filename, SDL_Renderer* renderer)
	{
		// Unload a previous image.
		if(texture != nullptr)
		{
			SDL_DestroyTexture(texture);
			texture = nullptr;
		}
		
		SDL_Surface* surface = IMG_Load(filename.c_str());
		
		// Check if it was loaded.
		if(surface == NULL)
		{
			std::cout << "Could not open " << filename << std::endl;
			return;
		}
		
		// Color key surface
		Uint32 key = SDL_MapRGB(surface->format, 0xFF, 0x00, 0xFF);
		SDL_SetColorKey(surface, SDL_TRUE, key);
		
		// Convert to texture.
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		surface = nullptr;
		
		// Get dimensions.
		SDL_QueryTexture(texture, nullptr, nullptr, &info.w, &info.h);
		input.w = info.w;
		input.h = info.h;
		
		return;
	}
	
	void Sprite::setWidth(int width)
	{
		input.w = width;
		return;
	}
	
	void Sprite::setHeight(int height)
	{
		input.h = height;
		return;
	}
	
	int Sprite::getWidth()
	{
		return input.w;
	}
	
	int Sprite::getHeight()
	{
		return input.h;
	}
	
	SDL_Rect* Sprite::getInputRect()
	{
		return &input;
	}
	
	SDL_Rect* Sprite::getOutputRect()
	{
		return &output;
	}
	
	void Sprite::selectRow(int row)
	{
		assert(row * input.h < info.h);
		selected_row = row;
		input.y = row * input.h;
		return;
	}
	
	void Sprite::selectColumn(int column)
	{
		assert(column * input.w < info.w);
		selected_column = column;
		input.x = column * input.w;
		return;
	}
	
	void Sprite::next()
	{
		// Wrap if at last image.
		if((selected_column + 1) * input.w == info.w)
			selected_column = 0;
		else
			selectColumn(++selected_column);
		return;
	}
	
	void Sprite::selectSprite(int x, int y)
	{
		selected_column = x;
		selected_row = y;
		SDL_Rect r = { (x * input.w), (y * input.h), input.w, input.h };
		input = r;
		return;
	}
}
