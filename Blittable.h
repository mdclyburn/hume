/*
 Hume Library Version 0.4.2
 */

#ifndef BLITTABLE_H
#define BLITTABLE_H	

#include <SDL2/SDL.h>
#include <iostream>

namespace hm
{
	// Defined alpha transparency values for convenience.
	enum ALPHA
	{
		TRANSPARENT = 0,
		TRANSLUCENT = 127,
		OPAQUE = 255
	};

	/*
	 Provides the basis for all objects that are able to
	 be drawn to the screen.
	 */
	class Blittable
	{
	public:
		Blittable();
		~Blittable();
		
		// Alpha
		int getAlpha();
		void setAlpha(int alphaValue);
		void modifyAlpha(int mod);
		
		// Positioning
		void setPosition(int x, int y);
		SDL_Rect getPosition();
		void move(int x, int y);
		void setx(int x);
		void sety(int y);
		
		// Texture Properties
		SDL_Rect getDimensions();
		virtual int getWidth();
		virtual int getHeight();
		SDL_Rect getInfo();
		SDL_Texture* getTexture();
		
		void destroyTexture();

	protected:
		int alpha;
		
		SDL_Rect info;
		SDL_Texture* texture;
	};
}

#endif