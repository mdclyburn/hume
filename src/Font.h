#ifndef FONT_H
#define FONT_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <iostream>

namespace hm
{
	/* Defines the three rendering modes available
	   to users: solid, shaded and blended. Solid
	   is the simplest and fastest, shaded takes two colors,
	   a text color and a background color and takes longer
	   than solid, but less time than blended. And blended
	   takes the longest to render out of the three. */

	enum RenderMode
	{
        	SOLID,
        	SHADED,
        	BLENDED
    	};

	/* Font class defines the basic functionality of a font
	   such as loading, coloring and rendering mode. Used in
	   conjunction with the Text class to render text. */

	class Font
	{
	public:
		Font(); // Basic ctor with no file loading.
		Font(std::string file, int ptsize = 16); // Ctor with file loading and size setting.
		~Font();

		static int getFontsOpen(); // Returns the amount of open fonts.

		void loadFont(std::string file, int ptsize = 16); // Loads a font after closing a present one.
		void closeFont(); // Closes a currently loaded font.
		TTF_Font* getFont(); // Get the font object pointer.

		void setSize(int size); // Resizes the font.

        	void setRenderMode(RenderMode rm); // Set the mode to render text in.
        	RenderMode getRenderMode(); // Get the mode to render text in.

	private:
		static int fontsOpen; // The amount of opened fonts.
		std::string file; // Where the last font opened is located.
		TTF_Font* font; // The font object.
        	RenderMode rm; // The mode to render the font in.
	};
}

#endif // FONT_H
