#ifndef BLITTABLE_H
#define BLITTABLE_H	

#include <SDL2/SDL.h>
#include <iostream>

namespace hm
{
	enum ALPHA
	{
		TRANSPARENT = 0,
		TRANSLUCENT = 127,
		OPAQUE = 255
	};

	class Blittable
	{
	public:
		Blittable();
		~Blittable();

		SDL_Texture* getTexture(); // Returns the pointer to the texture.
		
		void setPosition(int x, int y); // Sets the position of the Blittable.
		SDL_Rect* getPosition(); // Returns the SDL_Rect holding the position.
		
		void move(int x, int y); // Moves the Blittable in the specified direction.
		void setx(int x); // Sets the x position of the Blittable.
		void sety(int y); // Sets the y position of the Blittable.

		void setAlpha(int alphaValue); // Sets the alpha value.
		int getAlpha(); // Returns the alpha value of the Blittable.

	protected:
		int alpha;
		SDL_Texture* texture;
		SDL_Rect position;
	};
}

#endif