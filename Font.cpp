#include "Font.h"

namespace hm
{
	Font::Font()
	{
		font = NULL; // Safety first.
	}

	Font::Font(std::string file, int ptsize)
	{
		loadFont(file, ptsize);
	}

	void Font::loadFont(std::string file, int ptsize)
	{
		// Unload a previous font.
		if(font != NULL)
		{
			TTF_CloseFont(font); // Close the font file.
			font = NULL;
		}

		// Open the font.
		font = TTF_OpenFont(file.c_str(), ptsize);
		// Check it.
		if(font == NULL)
			std::cout << "Error, font not loaded." << std::endl;
		return;
	}

	TTF_Font* Font::getFont()
	{
		if(font == NULL)
			std::cout << "WARNING: Font is NULLed." << std::endl;
		return font;
	}
}
