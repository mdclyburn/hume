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

#ifndef TEXT_H
#define TEXT_H

#include <string>

#include <SDL2/SDL.h>

#include "Blittable.h"
#include "core/exceptions/SDLException.h"
#include "Font.h"

namespace hume
{
    /** A text resource
	 *
	 * Text is the Blittable representation of a text resource that can be drawn to the
	 * Window. In order to draw a Text object, it must be associated with a valid font.
	 */
	class Text : public Blittable
	{
	public:

		/** The default constructor.
		 *
		 * Constructs a Text object. The default foreground color is set to white, and the
		 * default background color is set to black.
		 */
		Text();

		/** The destructor.
		 *
		 */
		virtual ~Text();

		/** Set the font.
		 *
		 * Sets the font to be used when rendering the text. If the text has already been
		 * rendered with a call to Text::set_text(const std::stirng& text, SDL_Renderer& r),
		 * this function will _not_ cause the text to be rendered with the new font.
		 *
		 * \param font pointer to a valid Font
		 */
		void set_font(Font* const font);

		/** Render the text.
		 *
		 * Sets the text that will be drawn when the Text object is drawn. The rendering
		 * operation occurs during the execution of this function and can take varying
		 * amounts of time depending on the RenderMode that is being used. Calling this
		 * function when no font has been set will result in undefined behavior, but will
		 * probably cause the program to crash.
		 *
		 * \param text the text to be rendered
		 * \param r the renderer
		 */
		void set_text(const std::string& text, SDL_Renderer* r);

		/** Get the set text.
		 *
		 * Returns the currently set text.
		 */
		std::string get_text();

		/** Set the text color.
		 *
		 * Set the color of the text to be drawn to the screen.
		 *
		 * \param r the value of the red component
		 * \param g the value of the green component
		 * \param b the value of the blue component
		 */
		void set_color(const Uint8 r, const Uint8 g, const Uint8 b);

		/** Set the background color.
		 *
		 * Sets the background color of the text. This color will only show up if the
		 * Shaded RenderMode is in use.
		 *
		 * \param r the value of the red component
		 * \param g the value of the green component
		 * \param b the value of the blue component
		 */
		void set_bg_color(const Uint8 r, const Uint8 g, const Uint8 b);

	protected:

		/** The font used to render text. */
		Font* font;

		/** The text to be rendered. */
		std::string text;

		/** The color the text should be rendered with. */
		SDL_Color color;

		/** The color of the background with the Shaded RenderMode. */
		SDL_Color bg_color;
	};
}

#endif
