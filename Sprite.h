#ifndef SPRITE_H
#define SPRITE_H

#include "Image.h"
#include <iostream>

namespace hm
{
	class Sprite : public Image // Sprite class eases the use of sprite sheets.
	{
	public:
		Sprite(); // Constructor without image loading.
		Sprite(std::string filename); // Constructor with image loading.
		Sprite(std::string filename, int spriteWidth, int spriteHeight); // Image loading constructor with set sprite dimensions.

		void draw(SDL_Surface* surface); // Draws the current sprite to a passed-in surface.
		void selectSprite(int x, int y); // Sets the current sprite based on position on sheet. Starts at (0, 0).
		SDL_Rect* getCurrentSprite(); // Returns SDL_Rect spriteNumber.
		void nextSprite(); // Advances to the next sprite.
		void prevSprite(); // Goes back one sprite.
		void reset(); // Sets the sprite selected back to 0.
		SDL_Rect* getSpriteClip(); // Returns the spriteClip rect.

		void setSpriteSize(SDL_Rect spriteSize);
		void setSpriteSize(int width, int height);
		void setSpacing(int x, int y);
		void setOffset(int x, int y);

	private:
		SDL_Rect spriteNumber; // The sprites position on the sheet.
		SDL_Rect spriteClip; // The coordinates and clip size of the selected sprite.
		SDL_Rect spriteSpacing; // How many pixels between each sprite.
		SDL_Rect spriteOffset; // The starting position of the first sprite;

		void recalc(); // Recalculates the coordinates if sprite size changes.
	};
};

#endif