#include "Font.h"

// Static member variable.
int hm::Font::fontsOpen = 0;

namespace hm
{
	Font::Font()
	{
		// Check the status of SDL_ttf
		if(TTF_WasInit == 0)
			std::cout << "WARNING: SDL_ttf is not initialized!" << std::endl;
		file = "";
		font = NULL; // Safety first.
        setColor(0, 0, 0);
        setbColor(0, 0, 0);
        rm = SOLID;
	}

	Font::Font(std::string file, int ptsize)
	{
		// Check the status of SDL_ttf
		if(TTF_WasInit == 0)
			std::cout << "WARNING: SDL_ttf is not initialized!" << std::endl;
		this->file = file;
        font = NULL; // Safety first.
        loadFont(file, ptsize);
        setColor(0, 0, 0);
        setbColor(0, 0, 0);
        rm = SOLID;
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

	TTF_Font* Font::getFont()
	{
		if(font == NULL)
			std::cout << "WARNING: Font is NULL." << std::endl;
		return font;
	}

    void Font::setColor(Uint8 r, Uint8 g, Uint8 b)
    {
        color.r = r;
        color.g = g;
        color.b = b;
        return;
    }

    SDL_Color Font::getColor()
    {
        return color;
    }

    void Font::setbColor(Uint8 r, Uint8 g, Uint8 b)
    {
        bcolor.r = r;
        bcolor.g = g;
        bcolor.b = b;
        return;
    }

    SDL_Color Font::getbColor()
    {
        return bcolor;
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
