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

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "Image.h"

enum State
{
	IDLE,
	RUNNING_LEFT,
	RUNNING_RIGHT,
	SLOWING
};

namespace hm
{
	class Sprite : public Image
	{
	public:
		Sprite();
		~Sprite();
		
		void act();
		
		void setWidth(int width);
		void setHeight(int height);
		
		virtual SDL_Rect* getInputRect() = 0;
		virtual SDL_Rect* getOutputRect() = 0;
		
		void setMaxVelocity(float max_velocity);
		void setMinVelocity(float min_velocity);
		float getVelocity();
		void increaseVelocity();
		void decreaseVelocity();
		void slowVelocity(float factor);
		void setAcceleration(float acceleration);
		static void setFramesPerSecond(unsigned int fps);
		
		void setState(State state);
		State getState();
		
	protected:
		int width; // Sprite dimensions
		int height;
		
		float velocity; // Pixels per second.
		float max_velocity;
		float min_velocity;
		float acceleration;
		unsigned int initial_velocity;
		static unsigned int fps;
		
		State state;
		
		int selection_x; // position (not coordinate) of selected sprite
		int selection_y;
		SDL_Rect input; // Position/size from texture
		SDL_Rect output; // Position/size to window
		
		void selectSprite(int x, int y);
	};
}

#endif
