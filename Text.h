#ifndef TEXT_H
#define TEXT_H

#include "Blittable.h"
#include <SDL/SDL.h>
#include "Font.h"
#include <string>
#include <iostream>

namespace hm
{
	class Text : public Blittable
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

	private:
		std::string text; // The text the surface contains.
	};
}

#endif // TEXT_H
