#ifndef TEXT_H
#define TEXT_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>

namespace hm
{
	class Text
	{
		public:
			Text(); // Basic constructor.
			Text(std::string text, int size = 12); // Constructor, sets text with size defaulted to 12.
			Text(TTF_Font* font, std::string text, int size = 12); // Constructor, sets font to use, text and size defaulted to 12.
			
			void setText(std::string text); // Updates the text in the Text object.
			std::string getText(); // Gets the string being used for the text.
			
			void setFont(TTF_Font* font); // Sets the font to be used.
			TTF_Font* getFont(); // Gets the font currently being used.
			
			void setSize(int size); // Sets the size of the font.
			int getSize(); // Gets the font size being used.
			
			SDL_Surface* getSurface(); // Retrieve the SDL_Surface.
			
			void setColor(int r, int g, int b); // Sets the color to make the text.
			SDL_Color getColor(); // Gets the color being used for the text.
			
			void setPosition(int x, int y); // Sets the x and y position.
			SDL_Rect* getPosition(); //Returns the SDL_Rect containing the position.
			
		private:
			static TTF_Font* font; // The font of the text.
			SDL_Surface* sdltext; // The SDL_Surface text.
			SDL_Color color; // Color to make the text.
			SDL_Rect position; // Position of the text.
			std::string text; // The text for the Text.
			int size; // Size of the font used.
			
			void updateSurface(); // Sets the surface to the std::string.
	};
}

#endif
