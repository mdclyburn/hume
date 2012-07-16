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

		static int getFontsOpen(); // Returns the amount of open fonts.

		void loadFont(std::string file, int ptsize = 16); // Loads a font after closing a present one.
		void closeFont(); // Closes a currently loaded font.
		TTF_Font* getFont(); // Get the font object.

        void setColor(Uint8 r, Uint8 g, Uint8 b); // Set the color.
        SDL_Color getColor(); // Get the current color.
        void setbColor(Uint8 r, Uint8 g, Uint8 b); // Set the bcolor.
        SDL_Color getbColor(); // Get the bcolor.

        void setRenderMode(RenderMode rm); // Set the mode to render text in.
        RenderMode getRenderMode(); // Get the mode to render text in.

	private:
		static int fontsOpen; // The amount of opened fonts.
		TTF_Font* font; // The font object.
        SDL_Color color; // The color of the font.
        SDL_Color bcolor; // The bg color of the font (shaded).
        RenderMode rm; // The mode to render the font in.
	};
}

#endif // FONT_H
