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
		
		int getAlpha();
		void setAlpha(int alphaValue);
		
		void setPosition(int x, int y);
		SDL_Rect getPosition();
		void move(int x, int y);
		void setx(int x);
		void sety(int y);
		
		SDL_Rect getDimensions();
		virtual int getWidth();
		virtual int getHeight();
		
		SDL_Rect getInfo();
		SDL_Texture* getTexture();

	protected:
		int alpha;
		
		SDL_Rect info;
		SDL_Texture* texture;
	};
}

#endif