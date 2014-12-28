// Hume Library Version 0.6

#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <iostream>

#include <SDL2/SDL.h>

#include "Blittable.h"
#include "Font.h"
#include "Logger.h"

namespace hm
{
	/*
	 Text that can be drawn to the screen once provided
	 a font.
	 */
	class Text : public Blittable
    {
	public:
		Text();
		Text(const std::string& text, Font* const font);
		virtual ~Text();

		void setFont(Font* const font);
		
		void setText(const std::string& text, SDL_Renderer* const r);
		std::string getText() const;

		void setColor(const Uint8 r, const Uint8 g, const Uint8 b);
		void setbColor(const Uint8 r, const Uint8 g, const Uint8 b);
		SDL_Color getColor() const;
		SDL_Color getbColor() const;
		
		void render(SDL_Renderer* const r);

	private:
		Font* font;
		std::string text;
		SDL_Color color;
		SDL_Color bcolor;
	};
}

#endif // TEXT_H
