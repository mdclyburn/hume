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
		Text(); // Basic ctor.
		Text(Font* font); // Loads font.
		Text(std::string text, Font* font); // Loads font and sets string.

		SDL_Surface* getSurface(); // Returns the surface.

		void setText(std::string text); // Sets the text.
		std::string getText(); // Returns the current string.

        void setfColor(Uint8 r, Uint8 g, Uint8 b); // Sets the foreground color.
        SDL_Color getfColor(); // Gets the foreground color.
        void setbColor(Uint8 r, Uint8 g, Uint8 b); // Sets the background color.
        SDL_Color getbColor(); // Gets the background color.

		void setPosition(int x, int y); // Sets the position to draw the string.
		SDL_Rect* getPosition(); // Returns the position in an SDL_Rect.

	private:
		Font* font; // The font that should be used to draw the text.
		std::string text; // The text in std::string form.
		SDL_Surface* sdltext; // The SDL_Surface to hold the text.

        SDL_Color fcolor; // The foreground color of the text.
        SDL_Color bcolor; // The background color of the text.

		SDL_Rect position; // Holds the position of the text.

		void updateSurface(); // Updates the SDL_Surface to match the std::string.
	};
}

#endif // TEXT_H
