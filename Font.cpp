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
		font = NULL;
		openFont(filename, size);
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

	void Font::openFont(std::string filename, int size)
	{
		std::cout << "Opening " << filename << "..." << std::endl;
		if(font != NULL)
		{
			std::cout << "Previous font found. Closing..." << std::endl;
			TTF_CloseFont(font);
		}

		font = TTF_OpenFont(filename.c_str(), size);
		if(font == NULL)
			std::cout << "There was an error loading the font file " << filename << "..." << std::endl;
		else
			std::cout << filename << " was successfully opened." << std::endl;
		renderMode = SOLID;
		resetStyle();
		return;
	}

	void Font::resetStyle()
	{
		bold = false;
		italic = false;
		underline = false;
		strikethrough = false;
        style = TTF_STYLE_NORMAL; // Resets the style.
		setStyle();
		std::cout << "Style reset to " << style << "." << std::endl;

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
        if(font == NULL)
        {
            std::cout << "No font is loaded. Unable to set style." << std::endl;
            return;
        }

		TTF_SetFontStyle(font, style);
		return;
	}
}
