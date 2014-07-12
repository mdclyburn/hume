#include "Font.h"

int hm::Font::fontsOpen = 0;

namespace hm
{
	Font::Font() : file(""), font(NULL), rm(SOLID)
	{
		if(TTF_WasInit() == 0)
			std::cout << "WARNING: SDL_ttf is not initialized!" << std::endl;
	}

	Font::Font(std::string file, int ptsize) : file(file), font(NULL), rm(SOLID)
	{
		if(TTF_WasInit() == 0)
			std::cout << "WARNING: SDL_ttf is not initialized!" << std::endl;
		loadFont(file, ptsize);
	}

	Font::~Font()
	{
		closeFont();
	}

	int Font::getFontsOpen()
	{
		return fontsOpen;
	}

	void Font::loadFont(std::string file, int ptsize)
	{
		// Set our new font file string.
		this->file = file;

		// Unload a previous font.
		closeFont();

		// Open the font.
		font = TTF_OpenFont(file.c_str(), ptsize);
		// Check it.
		if(font == NULL)
			std::cout << "Could not load " << file << std::endl;
		else
			fontsOpen++; // Add to the amount of fonts open.
		return;
	}
	
	TTF_Font* Font::getFont()
	{
		if(font == NULL)
			std::cout << "WARNING: Font is NULL." << std::endl;
		return font;
	}

	void Font::closeFont()
	{
		if(font != NULL)
		{
			TTF_CloseFont(font);
			font = NULL;
			fontsOpen--;
		}

		return;
	}

	void Font::setSize(int size)
	{
		loadFont(file, size);
		return;
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
