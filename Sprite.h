//
//  Sprite.h
//  Game
//
//  Created by Marshall Clyburn on 12/30/13.
//  Copyright (c) 2013 Marshall Clyburn. All rights reserved.
//

#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "Image.h"

namespace hm
{
	class Sprite : public Image
	{
	public:
		Sprite();
		~Sprite();
		
		void loadImage(std::string filename, SDL_Renderer* renderer);
		
		void setWidth(int width);
		void setHeight(int height);
		int getWidth();
		int getHeight();
		
		SDL_Rect* getInputRect();
		SDL_Rect* getOutputRect();
		
		void selectRow(int row);
		void selectColumn(int column);
		void next();
		
	protected:
		int selected_column; // position (not coordinate) of selected sprite
		int selected_row;
		SDL_Rect input; // Position/size from texture
		SDL_Rect output; // Position/size to window
		
		void selectSprite(int x, int y);
	};
}

#endif
