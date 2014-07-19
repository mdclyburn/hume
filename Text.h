/*
 Hume Library Version 0.5
 */

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
		Text(std::string text, Font* font);
		virtual ~Text();

		void setFont(Font* font);
		
		void setText(std::string text, SDL_Renderer* r);
		std::string getText();

		void setColor(Uint8 r, Uint8 g, Uint8 b);
		void setbColor(Uint8 r, Uint8 g, Uint8 b);
		SDL_Color getColor();
		SDL_Color getbColor();
		
		void render(SDL_Renderer* r);

	private:
		Font* font;
		std::string text;
		SDL_Color color;
		SDL_Color bcolor;
	};
}

#endif // TEXT_H
