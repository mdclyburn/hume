#ifndef Window_H
#define Window_H

#include <string>
#include <iostream>

#include <SDL2/SDL.h>

#include "Blittable.h"
#include "Sprite.h"
#include "TileMap.h"

namespace hm
{
	class Window
	{
	public:
		Window(); // Default constructor sets dimensions to 640x480x32
		Window(int w, int h); // Constructor with custom dimensions.
		Window(std::string title, int w, int h, bool fs = false); // Constructor with custom dimensions and title.
		~Window(); // Destructor

		void setTitle(std::string title); // Sets the title of the window.
		bool getStatus(); // Returns true if the window isn't null. False otherwise.

		// Drawing Functions
		void draw(Blittable& b); // Draws a Blittable object to the window's screen.
		void draw(Blittable& b, int x, int y); // Draws a Blittable object to the window's screen, overriding the position set internally.
		void draw(Sprite& s); // Draw a sprite to the screen.
		void draw(TileMap& m); // Draws an entire map to the screen beginning at the coordinate point (0, 0).

		void clear(); // Blacks out the screen.
		void forceRefresh(); // Forces window to redraw.
		void refresh(); // Updates the screen.

		// Dimension Functions
		int getWidth(); // Returns the width of the window in pixels.
		int getHeight(); // Returns the height of the window in pixels.
		
		// Quick-Align Functions
		void center(Blittable& b); // Centers a blittable.
		void centerx(Blittable& b); // Centers a blittable on the X-Axis.
		void centery(Blittable& b); // Centers a blittable on the Y-Axis.
		void centerxco(Blittable& b, int x); // Centers a blittable along a specified X-Coordinate.
		void centeryco(Blittable& b, int y); // Centers a blittable along a specified Y-Coordinate.
		void centerco(Blittable& b, int x, int y); // Centers a blittable at a specified point.
		void top(Blittable& b); // Moves the blittable to the top without pushing it off-screen.
		void bottom(Blittable& b); // Moves the blittable to the bottom without pushing it off-screen.
		void left(Blittable& b); // Moves the blittable to the left without pushing off-screen.
		void right(Blittable& b); // Moves the blittable to the right without pushing off-screen.
		
		SDL_Renderer* getRenderer();

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
