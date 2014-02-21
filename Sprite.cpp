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
	unsigned int Sprite::fps = 30;
	
	Sprite::Sprite() :  velocity(0), max_velocity(150), min_velocity(-150), acceleration(1), initial_velocity(100), state(IDLE), selection_x(0), selection_y(0)
	{
		
	}
	
	Sprite::~Sprite()
	{
		
	}
	
	void Sprite::act()
	{
		switch(state)
		{
			case IDLE:
				break;
			case RUNNING_RIGHT:
				increaseVelocity();
				move(velocity / fps, 0);
				break;
			case RUNNING_LEFT:
				decreaseVelocity();
				move(velocity / fps, 0);
				break;
			case SLOWING:
				slowVelocity(10);
				move(velocity / fps, 0);
				break;
		}
	}
	
	void Sprite::setMaxVelocity(float max_velocity)
	{
		this->max_velocity = max_velocity;
		return;
	}
	
	void Sprite::setMinVelocity(float min_velocity)
	{
		this->min_velocity = min_velocity;
		return;
	}
	
	float Sprite::getVelocity()
	{
		return velocity;
	}
	
	void Sprite::increaseVelocity()
	{
		if(velocity >= 0) // If RUNNING_RIGHT or IDLE
			velocity += acceleration / 30;
		if(velocity < 0) // If RUNNING_LEFT
			slowVelocity(15);
		if(velocity > max_velocity) // Mustn't exceed max_acceleration
			velocity = max_velocity;
		return;
	}
	
	void Sprite::decreaseVelocity()
	{
		if(velocity <= 0) // If RUNNING_LEFT or IDLE
			velocity -= acceleration / 30;
		if(velocity > 0) // If RUNNING_RIGHT
			slowVelocity(25);
		if(velocity < min_velocity) // Mustn't exceed min_acceleration
			velocity = min_velocity;
		return;
	}
	
	void Sprite::slowVelocity(float decel_factor)
	{
		if(velocity == 0)
		{
			state = IDLE;
			return;
		}
		
		float velocity_loss = max_velocity * decel_factor / 100;
		//std::cout << "Slowing velocity: " << velocity << " by " << velocity_loss << std::endl;
		if(abs(int(velocity)) < abs(int(velocity_loss)))
			velocity = 0;
		else if(velocity > 0)
			velocity -= velocity_loss;
		else if(velocity < 0)
			velocity += velocity_loss;
		
		return;
	}
	
	void Sprite::setAcceleration(float acceleration)
	{
		this->acceleration = acceleration;
		return;
	}
	
	void Sprite::setFramesPerSecond(unsigned int fps)
	{
		Sprite::fps = fps;
		return;
	}
	
	void Sprite::setState(State state)
	{
		this->state = state;
		return;
	}
	
	State Sprite::getState()
	{
		return state;
	}
	
	void Sprite::selectSprite(int x, int y)
	{
		selection_x = x;
		selection_y = y;
		SDL_Rect r = { (x * width), (y * height), width, height };
		input = r;
		return;
	}
}
