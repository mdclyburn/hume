#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

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
		Font();
		Font(std::string file, int ptsize = 16);
		~Font();

		static int getFontsOpen();

		void loadFont(std::string file, int ptsize = 16);
		TTF_Font* getFont();
		void closeFont();

		void setSize(int size);

		void setRenderMode(RenderMode rm);
		RenderMode getRenderMode();

	private:
		static int fontsOpen;
		std::string file;
		TTF_Font* font;
		RenderMode rm;
	};
}

#endif
