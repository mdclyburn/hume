#ifndef BLITTABLE_H
#define BLITTABLE_H	

#include <SDL/SDL.h>
#include <iostream>

namespace hm
{
	class Blittable
	{
	public:
		Blittable();
		~Blittable();

		SDL_Surface* getSurface(); // Returns the pointer to the surface.
		void freeSurface(); // Frees the surface.
		
		void setPosition(int x, int y); // Sets the position of the Blittable.
		SDL_Rect* getPosition(); // Returns the SDL_Rect holding the position.
		
		void move(int x, int y); // Moves the Blittable in the specified direction.
		void setx(int x); // Sets the x position of the Blittable.
		void sety(int y); // Sets the y position of the Blittable.

		void setAlpha(Uint8 alpha); // Sets the alpha value.
		Uint8 getAlpha(); // Returns the alpha value of the Blittable.

	protected:
		Uint8 alpha;
		SDL_Surface* surface;
		SDL_Rect position;

		void optimize(); // Optimizes the surface for the screen.
	};
}

#endif