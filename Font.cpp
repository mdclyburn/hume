// Hume Library Version 0.6

#include "Font.h"

namespace hm
{
	Font::Font() : file(""), font(NULL), rm(SOLID)
	{
		if(TTF_WasInit() == 0)
			Logger::log("SDL_ttf is not initialized!", WARNING);
	}

	Font::Font(const std::string& file, const unsigned int ptsize) : file(file), font(NULL), rm(SOLID)
	{
		if(TTF_WasInit() == 0)
			Logger::log("SDL_ttf is not initialized!", WARNING);
		open(file, ptsize);
	}

	Font::~Font()
	{
		close();
	}

	void Font::open(const std::string& file, const unsigned int ptsize)
	{
		this->file = file;
		
		close();
		
		font = TTF_OpenFont(file.c_str(), ptsize);
		if(font == NULL)
			Logger::log("Could not load " + file + ".", ERROR);
		return;
	}
	
	TTF_Font* Font::getFont() const
	{
		return font;
	}

	void Font::close()
	{
		if(font != nullptr)
		{
			TTF_CloseFont(font);
			font = nullptr;
		}

		return;
	}

	void Font::setSize(unsigned int size)
	{
		open(file, size);
		return;
	}

	void Font::setRenderMode(RenderMode rm)
	{
		this->rm = rm;
		return;
	}
	
	RenderMode Font::getRenderMode() const
	{
		return rm;
	}
}
