/*
  Hume Library
  Copyright (C) 2015 Marshall Clyburn

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
  USA
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL_ttf.h>

#include "core/Component.h"
#include "Image.h"
#include "SDLTTFException.h"
#include "Window.h"

namespace hume
{
	typedef SDL_Color Color;

    /** Component for handling graphics.
	 *
	 * The Graphics class is a derivation of the Component. Its main purpose is
	 * to handle all graphical entities (Image, Text, Window) in a simple, elegant
	 * manner. The Graphics class can be subclassed to provide a more tailored
	 * implementation for different use cases.
	 */
	class Graphics : public Component
	{
	public:

		/** The default constructor.
		 *
		 * Constructs a Graphics object.
		 */
		Graphics();

		/** The destructor.
		 *
		 * If a Window is being managed by the Graphics object being destructed, it
		 * will be destroyed. Any references or pointers to it will no longer be valid.
		 */
		virtual ~Graphics();

		/** Initialize the Graphics component.
		 *
		 * Perform initialization of the Graphics object and the underlying SDL2
		 * libraries. SDL2's image and TTF libraries are initialized (the image library with
		 * support for JPEG and PNG files). This allows for the Graphics object to
		 * immediately be capable of loading images, given that it is managing a Window.
		 * Multiple calls to this function are not recommended, as its behavior is
		 * largely dependent on the behavior of the initialization of SDL2, which may or
		 * may not always be safe.
		 */
		virtual void initialize();

		/** Perform non-destructive cleanup.
		 *
		 * Shuts down the underlying SDL2 image and TTF libraries. Before using the
		 * component again, it is recommended that a call to Graphics::initialize() be
		 * made. Multiple calls to this function is not recommended, as its behavior is
		 * largely dependent on the behavior of the shutdown of SDL2, which may or may not
		 * always be safe.
		 */
		virtual void shutdown();

		/** Set the Window Graphics is to use.
		 *
		 * Provides the Graphics object with a Window that it is to manage. Once a Window
		 * is set it is possible to load images. Changing to a new Window once set and in
		 * use is not recommended and will result in undefined behavior.
		 *
		 * \param w the window
		 */
		void set_window(Window* const w);

		/** Returns the Window.
		 *
		 * Returns a pointer to the Window the Graphics object manages. This function will
		 * return nullptr if no Window is set. Assigning and using a single window with
		 * multiple Graphics objects simultaneously is _not_ recommended.
		 */
		Window* get_window() const;

		/** Sets the color for drawing operations.
		 *
		 * Sets the color to be used when drawing (e.g. draw_rect). The color is specified
		 * through R, G, B, and alpha values.
		 *
		 * \param r the red value
		 * \param g the green value
		 * \param b the blue value
		 * \param a the alpha value
		 */
		void set_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a);

		/** Sets the color for drawing operations.
		 *
		 * Sets the color to be used when drawing (e.g. draw_rect). The color is specified
		 * with a Color struct (really just an SDL_Color struct) with members r, g, b, and a.
		 * \param color struct containing the r, g, b, and a values
		 */
		void set_color(const Color& color);

		/** Returns the color used for drawing operations.
		 *
		 * Returns a Color struct (really just an SDL_Color struct) with members r, g, b, and a
		 * representing the red, green, blue, and alpha values currently used in drawing
		 * operations.
		 */
		Color get_color() const;

		/** Load an image.
		 *
		 * Loads the specified file into an Image and returns the Image. A Window must be
		 * set before calling this function. Calling this function without a Window set in
		 * Graphics will result in undefined behavior. Unless the function fails to allocate
		 * memory for the Image, this function will always return a valid pointer to an Image.
		 * To test if the image was loaded successfully, it is recommended to test for a
		 * non-nullptr value from Image::get_texture(). The supported image types are JPEG
		 * and PNG.
		 *
		 * \param filename the path to the image file
		 */
		Image* load_image(const std::string& filename);

		/** Load an image with a color key.
		 *
		 * Loads the specified file into an Image, color keying it with the specified values,
		 * and returns the Image. A Window must be set before calling this function. Calling
		 * this function without a Window set in Graphics will result in undefined behavior.
		 * Unless the function fails to allocate memory for the Image, this function will
		 * always return a valid pointer to an Image. To test if the image was loaded
		 * successfully, it is recommended to test for a non-nullptr value from
		 * Image::get_texture(). The suppported image types are JPEG and PNG.
		 *
		 * \param filename the path to the image file
		 * \param r the red value for the color key
		 * \param g the green value for the color key
		 * \param b the blue value for the color key
		 */
		Image* load_image(const std::string& filename, const Uint8 r, const Uint8 g, const Uint8 b);

		/** Draw a Blittable to the managed Window.
		 *
		 * Draws a Blittable to the Graphics object's Window with the Properties provided.
		 * This function is actually a wrapper around the
		 * Window::draw(const Blittable* b, const Properties& p) function provided for
		 * convenience.
		 */
		void draw(const Blittable* const b, const Properties& p);

		/** Draw a filled rectangle.
		 *
		 * Draws a filled rectangle with the specified size, position, and color.
		 *
		 * \param p a Properties struct containing the x-position, y-position, width, and height parameters
		 * \param r the red value for the color
		 * \param g the green value for the color
		 * \param b the blue value for the color
		 * \param a the alpha value for the color
		 */
		void draw_rect(const Properties& p, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

		/** Draw a filled rectangle.
		 *
		 * Draws a filled rectangle with the specified size, position, and color.
		 *
		 * \param x the x coordinate of the top-left corner of the rect
		 * \param y the y coordinate of the top-left corner of the rect
		 * \param w the width of the rect
		 * \param h the height of the rect
		 * \param r the red value for the color
		 * \param g the green value for the color
		 * \param b the blue value for the color
		 * \param a the alpha value for the color
		 */
		void draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

		/** Clear the Window.
		 *
		 * Clears the window. This function is actually a convenience wrapper around the
		 * Window::clear() function.
		 */
		void clear();

		/** Display the contents of the window.
		 *
		 * Reveals the contents of the Window (what was drawn to the screen since the last
		 * call to Graphics::refresh(). This function is actually a convenience wrapper
		 * around the Window::refresh() function.
		 */
		void refresh();

	protected:

		/** The Window managed by the Graphics object.
		 *
		 * To be able to perform useful work, the Graphics object should have exclusive
		 * possession of a Window object. This is said Window.
		 */
		Window* window;

		/** The color for drawing operations.
		 *
		 * A typedef'ed SDL_Color struct for storing the currently used color to draw.
		 */
		Color draw_color;
	};
}

#endif
