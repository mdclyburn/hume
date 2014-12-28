// Hume Library Version 0.6

#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Logger.h"

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
	   conjunction with the Text class to render text.
	 */

	class Font
	{
	public:
		Font();
		Font(const std::string& file, const int ptsize = 16);
		virtual ~Font();

		void open(const std::string& file, const int ptsize = 16);
		TTF_Font* getFont() const;
		void close();

		void setSize(const int size);

		void setRenderMode(const RenderMode rm);
		RenderMode getRenderMode() const;

	private:
		std::string file;
		TTF_Font* font;
		RenderMode rm;
	};
}

#endif
