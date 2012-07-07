#ifndef FONT_H
#define FONT_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <iostream>

namespace hm
{
    enum RenderMode
    {
        SOLID,
        SHADED,
        BLENDED
    };

	class Font
	{
	public:
		Font(); // Basic ctor with no file loading.
		Font(std::string file, int ptsize = 16); // Ctor with file loading and size setting.
		~Font();

		void loadFont(std::string file, int ptsize = 16); // Loads a font after closing a present one.
		TTF_Font* getFont(); // Get the font object.

        void setRenderMode(RenderMode rm); // Set the mode to render text in.
        RenderMode getRenderMode(); // Get the mode to render text in.

	private:
		TTF_Font* font; // The font object.
        RenderMode rm; // The mode to render the font in.
	};
}

#endif // FONT_H
