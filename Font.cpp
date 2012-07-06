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
        font = TTF_OpenFont(filename.c_str(), size);
        resetStyle();
        renderMode = SOLID;
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
        style = TTF_STYLE_NORMAL; // Resets the style.
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
		renderMode = rm;
	}

	int Font::getRenderMode()
	{
		return renderMode;
	}

	void Font::setStyle()
	{
        if(font == NULL)
        {
            std::cout << "No font is loaded. Unable to set style." << std::endl;
            return;
        }

        TTF_SetFontStyle(font, TTF_STYLE_NORMAL);
		return;
	}
}
