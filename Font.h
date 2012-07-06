#ifndef FONT_H
#define FONT_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>

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
		Font(); // default ctor.
		Font(std::string filename, int size = 16); // Loads file with default size being 16pt.
		~Font(); // Closes font, cleanup.

		void resetStyle(); // Sets all styles to false.
		void makeBold(bool bold); // Makes the font bold.
		void makeItalics(bool italic); // Italic fonts.
		void makeUnderline(bool underline); // Underline font.
		void makeStrikethrough(bool strikethrough); // Strike through the font.
		int getStyle(); // Gets the style of the font.

		void setRenderMode(RenderMode rm); // Sets the mode it should render in.
		int getRenderMode(); // Returns the renderMode variable.

	private:
		TTF_Font* font; // The font.

		// Font styles.
		int style;
		bool bold;
		bool italic;
		bool underline;
		bool strikethrough;

		int renderMode; // The mode to render the font in.

		void setStyle(); // Updates the font's style;
	};
}

#endif // FONT_H
