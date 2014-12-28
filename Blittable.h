// Hume Library Version 0.6

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
		virtual ~Blittable();
		
		// Alpha
		unsigned int getAlpha() const;
		void setAlpha(unsigned int alphaValue);
		void modifyAlpha(int mod);
		
		// Positioning
		void setPosition(int x, int y);
		SDL_Rect getPosition() const;
		void move(int x, int y);
		void setx(int x);
		void sety(int y);
		
		// Texture Properties
		SDL_Rect getDimensions() const;
		virtual unsigned int getWidth() const;
		virtual unsigned int getHeight() const;
		SDL_Rect getInfo() const;
		SDL_Texture* getTexture() const;
		
		void destroy();

	protected:
		unsigned int alpha;
		
		SDL_Rect info;
		SDL_Texture* texture;
	};
}

#endif
