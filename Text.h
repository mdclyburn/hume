#ifndef TEXT_H
#define TEXT_H

#include <SDL/SDL.h>
#include "Font.h"
#include <string>
#include <iostream>

namespace hm
{
	class Text
	{
	public:
		Text(); // Basic ctor with default text.
		Text(std::string text, Font& font);

		SDL_Surface* getSurface(); // Gets the SDL_Surface pointer.

		void setText(std::string text, Font& font); // Sets the text and surface.
		std::string getText(); // Gets the text.

		void setColor(Uint8 r, Uint8 g, Uint8 b); // Sets the color of the text.

		void setPosition(int x, int y); // Sets the x and y coordinates.
		SDL_Rect* getPosition(); // Returns the position.

	private:
		std::string text;
		SDL_Surface* sdltext;

		SDL_Color color; // Color of the text. Default is black.
		SDL_Rect position; // The position of the text.
	};
}

#endif // TEXT_H
