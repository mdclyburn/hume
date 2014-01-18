#ifndef Window_H
#define Window_H

#include <string>
#include <iostream>

#include <SDL2/SDL.h>

#include "Blittable.h"
#include "Sprite.h"

namespace hm
{
	class Window
	{
	public:
		Window(); // Default constructor sets dimensions to 640x480x32
		Window(int w, int h); // Constructor with custom dimensions.
		Window(std::string title, int w, int h); // Constructor with custom dimensions and title.
		~Window(); // Destructor

		void setTitle(std::string title); // Sets the title of the window.
		bool getStatus(); // Returns true if the window isn't null. False otherwise.

		// Drawing Functions
		void draw(Blittable& b); // Draws a Blittable object to the window's screen.
		void draw(Blittable& b, int x, int y); // Draws a Blittable object to the window's screen, overriding the position set internally.

		void clear(); // Blacks out the screen.
		void refresh(); // Updates the screen.

		// Dimension Functions
		int getWidth(); // Returns the width of the window in pixels.
		int getHeight(); // Returns the height of the window in pixels.

	private:
		int width;
		int height;
		bool needRefresh; // If the window needs to refresh.
		Uint32 clearColor; // The color to clear the window with.
		SDL_Window* window; // Window object
		SDL_Renderer* renderer;
	};
}

#endif
