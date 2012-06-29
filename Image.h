#ifndef IMAGE_H
#define IMAGE_H

#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <string>

namespace hm
{
	class Image
	{
	public:
		Image(); // Constructor without loading image.
		Image(std::string filename); // Constructor with image loading.

		void loadImage(std::string filename); // Loads an image.
		SDL_Surface* getImage(); // Returns a pointer to the image.
		virtual void draw(SDL_Surface* surface); // Draws the image to passed in surface.

		void setPosition(int x, int y); // Sets the position of the image.
		SDL_Rect* getPosition(); // Returns the position in an SDL_Rect.
		void move(int x, int y); // Moves the sprite in the specified direction.
		void setx(int x); // Sets the x position of the sprite for ease of use.
		void sety(int y); // Sets the y position of teh sprite for ease of use.

		void setColorKey(Uint8 r, Uint8 g, Uint8 b);

	protected:
		SDL_Surface* image; // The actual image.
		SDL_Rect position; // The x and y coordinates to draw too.
		
		void colorKey(); // Sets up the color key for transparency.
		void optimize(); // Optimizes image to the current display format. Called by void loadImage(std::string filename).
		void deleteImage(); // Gets rid of the loaded image.
	};
};

#endif