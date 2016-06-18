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

#ifndef IMAGE_H
#define IMAGE_H

#include <cassert>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "core/exceptions/SDLException.h"
#include "Blittable.h"

namespace hume
{
    /** A image resource.
	 *
	 * An Image is the Blittable representation of an image resource. An Image may be
	 * color keyed with a single color if specified before loading an image.
	 */
	class Image : public Blittable
	{
	public:

		/** The default constructor.
		 *
		 * Constructs an Image. The color key defaults to (255, 0, 255), a hot pink
		 * color.
		 */
		Image();

		/** The constructor allowing a color key to be set.
		 *
		 * Constructs and Image. The color key is set to the specified values.
		 *
		 * \param r the red value of the color key
		 * \param g the green value of the color key
		 * \param b the blue value of the color key
		 */
		Image(const Uint8 r, const Uint8 g, const Uint8 b);

		/** The destructor.
		 *
		 */
		virtual ~Image();

		/** Load an image.
		 *
		 * Opens an image resource from a file. This function requires the use of the
		 * SDL_Renderer associated with the Window that the Image may be drawn to. As
		 * such, this function is intended to called by a Graphics object managing a Window
		 * unless one chooses to not use the Graphics object. Calling this function when
		 * an image has already been loaded will result in undefined behavior, but will
		 * likely cause a memory leak. If the image fails to load, or convert to texture
		 * format, the program will exit by way of an assert statement.
		 *
		 * \param filename the path to the image file
		 * \param renderer the renderer of the SDL_Window the image may be drawn to
		 */
		virtual void open(const std::string& filename, SDL_Renderer* const renderer);

		/** Unload an image.
		 *
		 * Removes the image resource from memory. This function has the same effect as
		 * calling Image::destroy(), which has the same functionality of Blittable::destroy().
		 */
		virtual void close();

	protected:

		/** The color key.
		 *
		 * This is the color that is used to color key the image when it is loaded.
		 */
		SDL_Color color_key;
	};
}

#endif
