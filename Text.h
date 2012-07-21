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
        ~Text();

		SDL_Surface* getSurface(); // Gets the SDL_Surface pointer.

		void setText(std::string text, Font& font); // Sets the text and surface.
		std::string getText(); // Gets the text.

		void setPosition(int x, int y); // Sets the x and y coordinates.
        SDL_Rect* getPosition(); // Returns the position.

		void setAlpha(int alpha); // Set the alpha value.
		int getAlpha(); // Return alpha value.

	private:
		int alpha; // The alpha value of the text.
		std::string text;
		SDL_Surface* sdltext;

        SDL_Rect position; // The position of the text.

        void optimize(); // Optimize the sdltext.
	};
}

#endif // TEXT_H
