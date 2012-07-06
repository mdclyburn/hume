#include "Font.h"

namespace hm
{
	Font::Font()
	{
		font = NULL;
		resetStyle();
		renderMode = SOLID;
	}

	Font::Font(std::string filename, int size)
	{
		std::cout << "Constructing font." << std::endl;
		font = TTF_OpenFont(filename.c_str(), size);
		std::cout << "Opened font..." << std::endl;
		resetStyle();
		std::cout << "Reset style..." << std::endl;
		renderMode = SOLID;
		std::cout << "Set rendering mode to SOLID" << std::endl;
	}

	Font::~Font()
	{
		TTF_CloseFont(font);
		font = NULL;
	}

	TTF_Font* Font::getFont()
	{
		return font;
	}

	void Font::resetStyle()
	{
		bold = false;
		italic = false;
		underline = false;
		strikethrough = false;
		setStyle();

		return;
	}

	void Font::makeBold(bool bold)
	{
		this->bold = bold;
		setStyle();
		return;
	}

	void Font::makeItalics(bool italic)
	{
		this->italic = italic;
		setStyle();
		return;
	}

	void Font::makeUnderline(bool underline)
	{
		this->underline = underline;
		setStyle();
		return;
	}

	void Font::makeStrikethrough(bool strikethrough)
	{
		this->strikethrough = strikethrough;
		setStyle();
		return;
	}

	int Font::getStyle()
	{
		return style;
	}

	void Font::setFgColor(int r, int g, int b)
	{
		fgColor.r = r;
		fgColor.g = g;
		fgColor.b = b;

		return;
	}

	SDL_Color* Font::getFgColor()
	{
		return &fgColor;
	}

	void Font::setBgColor(int r, int g, int b)
	{
		bgColor.r = r;
		bgColor.g = g;
		bgColor.b = b;

		return;
	}

	SDL_Color* Font::getBgColor()
	{
		return &bgColor;
	}

	void Font::setRenderMode(RenderMode rm)
	{
		std::cout << "Render mode set to " << rm << std::endl;
		renderMode = rm;
	}

	int Font::getRenderMode()
	{
		return renderMode;
	}

	void Font::setStyle()
	{
		TTF_SetFontStyle(font, style);
		return;
	}
}
