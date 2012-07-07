#include "Font.h"

namespace hm
{
	Font::Font()
	{
		font = NULL; // Safety first.
        rm = SOLID;
	}

	Font::Font(std::string file, int ptsize)
	{
        std::cout << "Constructing a font..." << std::endl;
        font = NULL; // Safety first.
        loadFont(file, ptsize);
        rm = SOLID;
    }

    Font::~Font()
    {
        if(font != NULL)
        {
            TTF_CloseFont(font);
            font = NULL;
        }
    }

	void Font::loadFont(std::string file, int ptsize)
	{
		// Unload a previous font.
        std::cout << "Checking for a previously loaded font..." << std::endl;
		if(font != NULL)
		{
            std::cout << "Closing previous font..." << std::endl;
			TTF_CloseFont(font); // Close the font file.
			font = NULL;
		}

		// Open the font.
        std::cout << "Opening font..." << std::endl;
		font = TTF_OpenFont(file.c_str(), ptsize);
		// Check it.
        std::cout << "Check opened font..." << std::endl;
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

    void Font::setRenderMode(RenderMode rm)
    {
        this->rm = rm;
        return;
    }

    RenderMode Font::getRenderMode()
    {
        return rm;
    }
}
