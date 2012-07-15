#include "Font.h"

// Static member variable.
int hm::Font::fontsOpen = 0;

namespace hm
{
	Font::Font()
	{
		// Make sure SDL_ttf is active.
		if(TTF_WasInit == 0)
			TTF_Init();
		font = NULL; // Safety first.
        setColor(0, 0, 0);
        setbColor(0, 0, 0);
        rm = SOLID;
	}

	Font::Font(std::string file, int ptsize)
	{
		// Make sure SDL_ttf is active
		if(TTF_WasInit == 0)
			TTF_Init();
        std::cout << "Constructing a font..." << std::endl;
        font = NULL; // Safety first.
        loadFont(file, ptsize);
        setColor(0, 0, 0);
        setbColor(0, 0, 0);
        rm = SOLID;
    }

    Font::~Font()
    {
        if(font != NULL)
		{
			TTF_CloseFont(font);
			font = NULL;
			fontsOpen--;
        }

		// If that was the last font open, quit SDL_ttf for now.
		TTF_Quit();
    }

	int Font::getFontsOpen()
	{
		return fontsOpen;
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
			fontsOpen--;
		}

		// Open the font.
        std::cout << "Opening font..." << std::endl;
		font = TTF_OpenFont(file.c_str(), ptsize);
		// Check it.
        std::cout << "Check opened font..." << std::endl;
		if(font == NULL)
			std::cout << "Error, font not loaded." << std::endl;
		else
			fontsOpen++; // Add to the amount of fonts open.
		return;
	}

	TTF_Font* Font::getFont()
	{
		if(font == NULL)
			std::cout << "WARNING: Font is NULLed." << std::endl;
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
