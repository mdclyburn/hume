#ifndef TEXT_H
#define TEXT_H

#include <SDL\SDL.h>
#include <SDL\SDL_ttf.h>

namespace hm
{
	class Text // Wrapper class for SDL text.
	{
	public:
		Text(); // Basic constructor. No font loaded.
		Text(std::string font, int size = 12); // Constructor with font to load and size default to 12.

		static void loadFont(std::string font, int size); // Opens a font file to use.
		static void closeFont(); // Closes the font.

		void setText(std::string text); // Sets the SDL_Surface to the desired text.
		void setText(std::string text, int size); // Sets the text and size.

		static void setSize(int size); // Sets the size of the text.

	private:
		static TTF_Font font; // The font used to render the text.
		SDL_Surface* text; // The surface that contains the text.

		static bool checkFont(); // Checks the status of the font file.
	};
};

#endif