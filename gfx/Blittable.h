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

#ifndef BLITTABLE_H
#define BLITTABLE_H

#include <cassert>

#include "SDL2/SDL.h"

#include "core/exceptions/SDLException.h"

/** A drawable graphic.
 *
 * Anything that can be drawn to the screen is considered a
 * Blittable. This includes images and text. The Blittable
 * class is an abstract class defining properties such as
 * transparency, width, height, and the loaded texture itself.
 * Subclasses should define a method with which one can load the
 * texture into memory. See the Text and Image classes for examples.
 */
class Blittable
{
public:

	/** The default constructor.
	 *
	 * Initializes a Blittable.
	 */
    Blittable();

	/** The destructor.
	 *
	 * Invokes Blittable::destroy() if a texture is currently loaded.
	 */
    virtual ~Blittable();

	/** Set the transparency of a Blittable.
	 *
	 * Directly set the alpha (transparency) value of texture. Valid
	 * values range from 0 (not visible) to 255 (completely opaque). Calling
	 * this function when a texture is not loaded will result in undefined
	 * behavior.
	 *
	 * \param a the new alpha value
	 */
    void set_alpha(const Uint8 a);

	/** Change the alpha value.
	 *
	 * Changes the alpha value by some amount relative to
	 * its current value. If the current alpha value for a texture is
	 * set to 234, and the value of the parameter passed to this function
	 * is 4, then the texture's alpha value will be set to 238. This also
	 * works the same way for negative values. Calling this function when
	 * a texture is not loaded will result in undefined behavior.
	 *
	 * \param m the amount to modify the alpha value by
	 */
    void modify_alpha(const short m);

	/** Returns the current alpha value.
	 *
	 * Retrieves the alpha value from the texture and returns the value.
	 * Calling this function when a texture is not loaded will result in
	 * undefined behavior.
	 */
    Uint8 get_alpha() const;

	/** Returns the width of the loaded texture.
	 *
	 * Returns the width of the loaded texture. Calling this function when a texture
	 * is not loaded will result in undefined values.
	 */
    unsigned int get_width() const;

	/** Returns the height of the loaded texture.
	 *
	 * Returns the height of the loaded texture. Calling this function when a texture
	 * is not loaded will result in undefined values.
	 */
    unsigned int get_height() const;

	/** Returns a pointer to the texture.
	 *
	 * Returns a pointer to the texture the Blittable is associated with. This function
	 * will return nullptr if no texture is loaded.
	 */
    SDL_Texture* get_texture() const;

	/** Removes a texture from memory.
	 *
	 * Explicitly removes a texture. The texture this Blittable is associated
	 * with becomes a nullptr. Calling this function when a texture is not
	 * loaded will result in undefined behavior.
	 */
    void destroy();

protected:

	/** A texture's imensional information.
	 *
	 * Contains four important values: 'length', 'width', 'x', and 'y'. 'length' is
	 * the length of the current texture. The 'width' is the width of the current
	 * texture. 'x' is the x coordinate to draw the texture at when being drawn to
	 * the screen or window. 'y' is the y coordinate to draw the texture at when being
	 * drawn to the screen or window.
	 */
    SDL_Rect info;

	/** The underlying texture.
	 *
	 * The texture that the Blittable represents. There is no way to load the texture
	 * from the Blittable class. This is a derivative-specific feature.
	 */
    SDL_Texture* texture;
};

#endif
