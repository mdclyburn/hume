#ifndef Window_H
#define Window_H

#include <SDL/SDL.h>
#include "Blittable.h"
#include "Sprite.h"
#include <string>
#include <iostream>

namespace hm
{
	class Window
	{
	public:
		Window(); // Default constructor sets dimensions to 640x480x32
		Window(int w, int h, int bpp = 32); // Constructor with custom dimensions.
		Window(std::string title, int w, int h, int bpp = 32); // Constructor with custom dimensions and title.
		~Window(); // Destructor

        bool getStatus(); // Returns true if the window isn't null. False otherwise.

		void draw(Blittable& b); // Draws a Blittable object to the window's screen.
		void draw(Sprite& s); // Draws sprite to screen.

		void clear(); // Blacks out the screen.
		Uint32 getClearColor(); // Gets the currently used clear color.
		void setClearColor(Uint32 clearColor); // Changes refresh color with unsigned 32-bit integer.
		void setClearColor(Uint8 red, Uint8 green, Uint8 blue); // Changes refresh color with 8-bit integers.
		void resetClearColor(); // Changes the clear color back to 255, 0, 255.
		void refresh(); // Updates the screen.

	private:
		bool needRefresh; // If the window needs to refresh.
		Uint32 clearColor; // The color to clear the window with.
		SDL_Surface* screen; // The actual surface we flip.

		friend void center(Blittable& b, Window& w);
	};
};

#endif
