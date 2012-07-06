#include "Font.h"

namespace hm
{
	Font::Font()
	{
		font = NULL;
		resetStyle();
	}

	Font::Font(std::string filename, int size)
	{
		font = TTF_OpenFont(filename.c_str(), size);
		resetStyle();
	}

	Font::~Font()
	{
		TTF_CloseFont(font);
		font = NULL;
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
		TTF_SetFontStyle(font, style);
		return;
	}
}
