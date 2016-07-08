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

#ifndef WINDOW_H
#define WINDOW_H

#include "Blittable.h"
#include "Core/Exceptions/SDLException.h"
#include "Properties.h"
#include "WindowSettings.h"

namespace hume
{
    /** A window that can have a Blittable drawn to it.
	 *
	 * The Window represents, as its name suggests, a single window. The Window can have
	 * its settings changed with the WindowSettings struct. Typically, a Window will be
	 * managed by a single Graphics object at a time. This class wraps the SDL_Window and
	 * SDL_Renderer. It is still possible to directly use the SDL_Window and SDL_Renderer
	 * with the Window::get_window() and Window::get_renderer() calls.
	 */
	class Window
	{
	public:

		/** The default constructor.
		 *
		 * Constructs a window. The constructor does not actually make the Window usable.
		 */
		Window();

		/** The destructor.
		 *
		 *
		 */
		virtual ~Window();

		/** Initializes the Window.
		 *
		 * Using the internal WindowSettings (which will default if not explicitly set), the Window
		 * initializes itself. After this function returns, the Window will be ready for the
		 * draw, present, and clear operations.
		 */
		void create();

		/** Destroys the internal window resources.
		 *
		 * Deinitializes the wrapped SDL_Window and SDL_Renderer, freeing up resources.
		 */
		void destroy();

		/** Set window properties.
		 *
		 * Applies a settings from the provided WindowSettings struct to the Window. If the Window
		 * has already been created, and the settings for the window are different from what the
		 * Window is currently using, it will be dynamically adjusted.
		 *
		 * \param w the settings to be applied
		 */
		void apply(WindowSettings& w);

		/** Retrieve current settings.
		 *
		 * Returns the WindowSettings that will be used or are in use by the Window.
		 */
		WindowSettings get_settings() const;

		/** Retrieve the SDL_Window.
		 *
		 * Returns a pointer to the underlying SDL_Window.
		 */
		SDL_Window* get_window();

		/** Retrieve the SDL_Renderer.
		 *
		 * Returns a pointer to the underlying SDL_Renderer.
		 */
		SDL_Renderer* get_renderer();

		/** Draw a Blittable with Properties.
		 *
		 * Draws the provided Blittable to the Window according to the Properties provided. If the
		 * width or height values are 0, then the Blittable will be drawn with its native size. If
		 * either the source width or source height values are 0, then the entire Blittable will
		 * be drawn. Calling this function before Window::create() will result in undefined
		 * behavior.
		 *
		 * \param b the Blittable to be drawn
		 * \param p properties to be used when drawing the Blittable
		 */
		void draw(const Blittable* const b, const Properties& p);

		/** Display what has been drawn.
		 *
		 * Updates the display area, showing what has been drawn to the window since the last call
		 * to this function. Calling this function before Window::create() will result in undefined
		 * behavior.
		 */
		void present();

		/** Clear the window.
		 *
		 * Draws over the entire window with the clearing color (currently, only black is supported).
		 * Calling this function before Window::create() will result in undefined behavior.
		 */
		void clear();

	protected:

		/** The underlying SDL_Window. */
		SDL_Window* window;

		/** The underlying SDL_Renderer. */
		SDL_Renderer* renderer;

		/** The window's current settings. */
		WindowSettings settings;
	};
}

#endif
