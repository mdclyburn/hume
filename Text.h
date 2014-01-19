#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <iostream>

#include <SDL2/SDL.h>

#include "Blittable.h"
#include "Font.h"

namespace hm
{
	class Text : public Blittable
    {
	public:
		Text(); // Basic ctor with default text.
		Text(std::string text, Font* font);
		~Text();

		SDL_Texture* getTexture();

		void setFont(Font* font); // Sets the font to be used.
		void setText(std::string text);
		std::string getText(); // Gets the text.

		void setColor(Uint8 r, Uint8 g, Uint8 b); // Sets color.
		void setbColor(Uint8 r, Uint8 g, Uint8 b); // Sets the background color.
		SDL_Color getColor(); // Returns the set color.
		SDL_Color getbColor(); // Returns the set background color.
		
		void render(SDL_Renderer* r); // Produce texture with current properties.

	private:
		Font* font; // The font used to render the text.
		std::string text; // The text the surface contains.
		SDL_Color color; // The color of the text.
		SDL_Color bcolor; // The background color. Used when in shaded rendering mode.
	};
}

#endif // TEXT_H
