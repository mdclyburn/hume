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

#ifndef FONT_H
#define FONT_H

#include <cassert>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "core/exceptions/SDLTTFException.h"
#include "RenderMode.h"

/** A font that has been loaded into memory.
 *
 * In order for the Text class to be useful, one must first provide
 * a Font for it to use. The Font class acts as a wrapper for SDL2's
 * TTF_Font, managing the opening, closing, and manipulation of
 * TTF_Font's properties. All font file types supported by SDL2_ttf
 * are supported.
 */
class Font
{
public:

	/** The default constructor.
	 *
	 * Constructs a Font. The rendering mode defaults to RenderMode::Blended.
	 */
    Font();

	/** The destructor.
	 *
	 * Closes the encapsulated font if it is open.
	 */
    virtual ~Font();

	/** Opens a font file.
	 *
	 * Loads a font to be used at the specified size. All fonts supported by
	 * SDL2_ttf are supported. Any Font that already has a font loaded should
	 * make a call to Font::close() before calling this function. This function
	 * will not close a font already opened, possibly resulting in a memory leak.
	 *
	 * \param file_name the path to the font file to be loaded
	 * \param pt_size the size of the font to be used in points
	 */
    void open(const std::string& file_name, const unsigned int pt_size);

	/** Close an open font.
	 *
	 * Unloads a font from memory. Calling this function when a font is not currently
	 * loaded will result in undefined behavior.
	 */
    void close();

	/** Set the size of the loaded font.
	 *
	 * Changes the font size of the current font. This function is required to
	 * reopen the original font file, and thus expects that the path of the
	 * font has not changed since it was last loaded. Calling this function when
	 * a font is not currently loaded will result in undefined behavior.
	 *
	 * \param pt_size the new font size in points
	 */
    void set_size(const unsigned int pt_size);

	/** Set the rendering mode.
	 *
	 * Sets the method of rendering text using this Font. See RenderMode.
	 *
	 * \param render_mode the RenderMode to use
	 */
    void set_render_mode(const RenderMode& render_mode);

	/** Returns the current RenderMode.
	 *
	 * Returns the current RenderMode the Font uses.
	 */
    RenderMode get_render_mode();

	/** Returns the loaded font.
	 *
	 * Returns a pointer to the loaded font. This function will return nulllptr if
	 * no font has been loaded.
	 */
    TTF_Font* get_font();

protected:

	/** The underlying SDL2 font. */
    TTF_Font* font;

	/** The path to the font file loaded.
	 *
	 * The path to the font file that was last loaded. This is used when the
	 * Font::set_size(const unsigned int pt_size) function is called to reopen
	 * the font with the new size.
	 */
    std::string file_name;

	/** The RenderMode in use when Text drawn to the screen uses this Font.
	 *
	 * The RenderMode in use when Text that is drawn to the screen uses this Font. See
	 * RenderMode for details.
	 */
    RenderMode render_mode;
};

#endif
