/*
 Hume Library Version 0.4.3
 */

#include "Font.h"

int hm::Font::fontsOpen = 0;

namespace hm
{
	Font::Font() : file(""), font(NULL), rm(SOLID)
	{
		if(TTF_WasInit() == 0)
			Logger::log("SDL_ttf is not initialized!", WARNING);
	}

	Font::Font(std::string file, int ptsize) : file(file), font(NULL), rm(SOLID)
	{
		if(TTF_WasInit() == 0)
			Logger::log("SDL_ttf is not initialized!", WARNING);
		open(file, ptsize);
	}

	Font::~Font()
	{
		close();
	}

	int Font::getFontsOpen()
	{
		return fontsOpen;
	}

	void Font::open(std::string file, int ptsize)
	{
		this->file = file;
		
		close();
		
		font = TTF_OpenFont(file.c_str(), ptsize);
		if(font == NULL)
			Logger::log("Could not load " + file + ".", ERROR);
		else
			fontsOpen++;
		return;
	}
	
	TTF_Font* Font::getFont()
	{
		return font;
	}

	void Font::close()
	{
		if(font != nullptr)
		{
			TTF_CloseFont(font);
			font = nullptr;
			fontsOpen--;
		}

		return;
	}

	void Font::setSize(int size)
	{
		open(file, size);
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
